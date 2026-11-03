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

auto start = std::chrono::high_resolution_clock::now();
int main(int argc, char* argv[]) {
    if(MODE == "DEBUG") {
        std::cout << "[DEBUG MODE] argc: " << argc << std::endl;
    }
    parse_args(argc, argv);

    
    // calculate elapsed time since program start
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    return 0;
}