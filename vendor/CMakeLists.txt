add_library(minunit_lib INTERFACE)
add_library(fff_lib INTERFACE)
add_library(clogger_lib STATIC
    c-logger/src/logger.h
    c-logger/src/loggerconf.h
    c-logger/src/logger.c
    c-logger/src/loggerconf.c
)

target_include_directories(minunit_lib INTERFACE minunit)
target_include_directories(fff_lib INTERFACE fff)
target_include_directories(clogger_lib PUBLIC c-logger/src)
