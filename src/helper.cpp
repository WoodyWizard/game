#include "helper.h"

namespace {
    #include <iostream>
}

int print_error(const char* error) {
    std::cout << error << std::endl;
    return 1;
}