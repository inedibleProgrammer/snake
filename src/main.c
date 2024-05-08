#include <stdio.h>
#include "Snake.h"

int main(int argc, char** argv)
{
    Snake_T mainSnake;
    Snake_Init(&mainSnake);
    printf("Main snake char: %c\n", mainSnake.headSymbol);
    return 0;
}



