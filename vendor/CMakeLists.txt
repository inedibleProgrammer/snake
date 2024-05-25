add_library(ctest_lib STATIC ctest/ctest.h ctest/main.c)
add_library(fff_lib INTERFACE)
add_library(clogger_lib STATIC
    c-logger/src/logger.h
    c-logger/src/loggerconf.h
    c-logger/src/logger.c
    c-logger/src/loggerconf.c
)

target_include_directories(ctest_lib PUBLIC ctest)
target_include_directories(fff_lib INTERFACE fff)
target_include_directories(clogger_lib PUBLIC c-logger/src)
