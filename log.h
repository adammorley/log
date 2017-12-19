#include <stdarg.h>
#include <stdbool.h>

/*
    log a message to stdout
*/
void LOG(const char* level, const char* func, const char* format, va_list args);

/*
    write a debug message to stdout
*/
void LOG_DEBUG(const char* format, const char* func, ...);

/*
    extension of the assert function
*/
void Assert(bool condition, const char* func, const char* format, ...);

/*
    enable debug logging
*/
void _enable_logging(bool debug);
