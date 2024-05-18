add_executable(snake_bin
    main.c
    snake.h
    snake.c
)

target_link_libraries(snake_bin
    clogger_lib
)

# target_include_directories(snake_bin PUBLIC ../vendor/c-logger/src)
