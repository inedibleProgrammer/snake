#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdbool.h>

typedef struct
{
    char headSymbol;
} Snake_T;

bool Snake_ReturnsTrue(void);
void Snake_Init(Snake_T *pSnake);

#endif /* SNAKE_H_ */
