#include <iostream>
#include <chrono>
#include <vector>
#include "jfcli/exceptions.h"
#include "jfcli/help.h"
#include "jfcli/version.h"
#include "definitions.h"

bool show_time = true;

void parse_args(int argc, char* argv[]) {
    if(argc == 1) {
        throw_noinputexcep();
        return;
    }
    
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // check first-position arguments for -v / -h
    if(args[0] == "-h") {
        show_help();
        show_time = false;
    }
    else if(args[0] == "-v") {
        show_version();
        show_time = false;
    }
}

auto start = std::chrono::high_resolution_clock::now();
int main(int argc, char* argv[]) {
    if(MODE == "DEV") {
        std::cout << "[DEBUG MODE] argc: " << argc << std::endl;
    }
    
    parse_args(argc, argv);
    
    // calculate elapsed time since program start
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if(show_time) {
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    }
    return 0;
}