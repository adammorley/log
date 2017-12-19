#include <stdbool.h>

#include "log.h"

int main() {
    LOG_DEBUG("logging message won't print\n", __func__);
    _enable_logging(true);
    LOG_DEBUG("logging message does print\n", __func__);
    return 0;
}
