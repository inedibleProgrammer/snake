file(GLOB snake_src
    main.c
    game.h
    game.c
    snake.h
    snake.c
)

add_executable(snake_bin
    ${snake_src}
)

target_link_libraries(snake_bin
    clogger_lib
)
