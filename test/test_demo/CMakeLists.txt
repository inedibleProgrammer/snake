add_executable(test_demo_bin
    test_demo.c
)

target_include_directories(test_demo_bin PUBLIC src)

target_link_libraries(test_demo_bin
    minunit_lib
    fff_lib
)

add_test(test_demo_t test_demo_bin)
