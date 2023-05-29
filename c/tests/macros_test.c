#include "utils/macros.h"

int main()
{
    LOG("keke");
    LOG("keke %d %d", 1, 3);

    LOG_ERROR("keke");
    LOG_ERROR("keke %d %d", 1, 3);

    return 0;
}
