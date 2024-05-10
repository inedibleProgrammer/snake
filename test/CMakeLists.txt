enable_testing()

add_executable(test_snake
    Test_Snake.c
)


target_include_directories(test_snake PUBLIC src)
# target_include_directories(test_snake PUBLIC ${CMAKE_SOURCE_DIR}/vendor/minunit)
# target_include_directories(test_snake PUBLIC minunit)

target_link_libraries(test_snake
    minunit_lib
)


add_test(test_snake_t test_snake)
