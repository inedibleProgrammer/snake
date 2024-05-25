#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "snake.h"
#include "game.h"
#include "logger.h"


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
    // write(STDOUT_FILENO, "\033[H\033[J", sizeof("\033[H\033[J"));
    write(STDOUT_FILENO, "\033[H", sizeof("\033[H"));
    for(int i = 0; i < GRID_HEIGHT; i++)
    {
        puts(m_grid[i]);
    }
}



int Game_Run(void)
{
    while(1)
    {
        // double start = getCurrentTime();
        // processInput();
        // update();
        render();
        // sleep(start + MS_PER_FRAME - getCurrentTime());
        sleep60fps();
    }
}
