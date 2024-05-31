#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <termios.h>
#include <stdbool.h>
#include <sys/ioctl.h>

#include "snake.h"
#include "game.h"
#include "logger.h"

static bool m_quit = false;

static void* getUserInputThread(void* arg)
{
    char buffer[128];
    int num = 0;
    char c;
    // printf("thread running");
    while(1)
    {
        // num = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        c = getchar();
        if(c == 'q')
        {
            m_quit = true;
            // printf("q pressed");
        }
        // printf("Test");
        // printf("%s", buffer);
    }
}

static void processInput()
{
    
}

static double getCurrentTime()
{
    struct timespec t1;
    clock_gettime(CLOCK_REALTIME, &t1);
    double difference;
    while(1)
    {
        struct timespec t2;
        clock_gettime(CLOCK_REALTIME, &t2);
        difference = (double)(t2.tv_sec - t1.tv_sec);
        // double seconds = difference / 1e-9;

        if(difference >= 15.0)
        {
            break;
        }
    }

    printf("difference: %f\n", difference);
}



static void sleep60fps(void)
{
    struct timespec t1;
    t1.tv_sec = 0;
    t1.tv_nsec = 16666666;
    nanosleep(&t1, NULL);
}

#define GRID_WIDTH (10)
#define GRID_HEIGHT (11)
static char m_grid[GRID_WIDTH][GRID_HEIGHT] = {
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
    "XXXXXXXXXX",
};
static void render(void)
{
    // system("clear");
    // printf("\033[H\033[J");
    write(STDOUT_FILENO, "\033[H\033[J", sizeof("\033[H\033[J")); // Move cursor and clear screen
    // write(STDOUT_FILENO, "\033[H", sizeof("\033[H")); // Move cursor only
    for(int i = 0; i < GRID_HEIGHT; i++)
    {
        printf("%s\n", m_grid[i]);
        printf("\033[G");
        // puts("\033[G");
    }
}


void demoTerm(void)
{
    // 100, 40 seems to be the max on my laptop
    struct winsize w;
    w.ws_col = 100;
    w.ws_row = 40;

    // Read window size
    // ioctl(0, TIOCGWINSZ, &w);
    // printf("col: %d\n", w.ws_col);
    // printf("row: %d\n", w.ws_row);
    
    // Set window size
    // ioctl(STDOUT_FILENO, TIOCSWINSZ, &w);
    printf("\033[8;%d;%dt", 40, 40);
    fflush(stdout);
    while(1)
    {
    }
}



int Game_Run(void)
{
    // demoTerm();
    struct termios oldTermios;
    struct termios newTermios;
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
    cfmakeraw(&newTermios);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    
    pthread_t userInputThreadID;
    pthread_create(&userInputThreadID, NULL, &getUserInputThread, NULL);
    while(1)
    {
        // double start = getCurrentTime();
        processInput();

        if(m_quit == true)
        {
            break;
        }
        // update();
        render();
        // sleep(start + MS_PER_FRAME - getCurrentTime());
        sleep60fps();
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
}
