#include "app.h"
#include "utils/error.h"

#include <print>

int main()
{
    try {
        nightfall::App app;
        app.run();
    } catch (const nightfall::Error& err) {
        std::println(stderr, "\n{}", err.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
