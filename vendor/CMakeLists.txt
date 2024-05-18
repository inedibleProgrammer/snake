add_library(minunit_lib INTERFACE)
add_library(fff_lib INTERFACE)

target_include_directories(minunit_lib INTERFACE minunit)
target_include_directories(fff_lib INTERFACE fff)
