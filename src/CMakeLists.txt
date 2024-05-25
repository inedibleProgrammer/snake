file(GLOB snake_src
    *.c
    *.h
)

add_executable(snake_bin
    ${snake_src}
)

target_link_libraries(snake_bin
    clogger_lib
)
