#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void LOG(const char* level, const char* func, const char* format, va_list args) {
    printf("%s %s: ", level, func);
    vprintf(format, args);
    printf("\n");
}

static bool logDEBUG = false;
void LOG_DEBUG(const char* format, const char* func, ...) {
    if (logDEBUG) {
        va_list args;
        va_start(args, func);
        LOG("DEBUG", func, format, args);
        va_end(args);
    }
}

static bool logASSERT = true;
void Assert(bool condition, const char* func, const char* format, ...) {
    if (!condition && logASSERT) {
        va_list args;
        va_start(args, format);
        LOG("ASSERT", func, format, args);
        va_end(args);
    }
    assert(condition);
}

void _enable_logging(bool debug) {
    if (debug) logDEBUG = true;
}
