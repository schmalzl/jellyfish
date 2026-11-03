#include <iostream>
#include <chrono>
#include "jfcli/exceptions.h"

#define MODE "DEBUG"

void parse_args(int argc, char* argv[]) {
    if(argc == 1) {
        throw_noinputexcep();
        return;
    }
    else {

    }
}

int main(int argc, char* argv[]) {
    if(MODE == "DEBUG") {
        std::cout << "[DEBUG MODE] argc: " << argc << std::endl;
    }
    parse_args(argc, argv);
    return 0;
}