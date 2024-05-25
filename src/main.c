#include "logger.h"
#include "game.h"

int main(int argc, char** argv)
{
    int exitCode = 0;
    logger_initFileLogger("log.txt", 1024 * 1024, 5);
    logger_setLevel(LogLevel_DEBUG);
    LOG_INFO("file logging init");
    // LOG_DEBUG("format example: %d%c%s", 1, '2', "3");

    exitCode = Game_Run();

    return exitCode;
}



