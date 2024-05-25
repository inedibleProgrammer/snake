#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "logger.h"

int main(int argc, char** argv)
{
    Snake_T mainSnake;
    Snake_Init(&mainSnake);
    printf("Main snake char: %c\n", mainSnake.headSymbol);

    logger_initFileLogger("log.txt", 1024 * 1024, 5);
    logger_setLevel(LogLevel_DEBUG);
    LOG_INFO("file logging init");
    // LOG_DEBUG("format example: %d%c%s", 1, '2', "3");


    // system("clear");
    return 0;
}



