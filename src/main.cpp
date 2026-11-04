#include <iostream>
#include <chrono>
#include <vector>
#include "jfcli/exceptions.h"
#include "jfcli/help.h"
#include "jfcli/version.h"
#include "definitions.h"
#include <filesystem>
#include "globals.h"
#include "parser/jfparse.h"
namespace fs = std::filesystem;

bool show_time = true;

std::string get_output_path(const std::string& input_file,
                            const std::string& output_name)
{
    fs::path input(input_file);
    return (input.parent_path() / output_name).string();
}

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
    else {
        // FORMAT: jellyfish <input> -o <output> (-v1)
        std::string in_path = args[0];
        std::string out_path;
        if(args[1] == "-o") {
            if(args.size() > 2) {
                out_path = args[2];
            }
        }
        else {
            // throw_nooutputpath
            throw_nooutputpath();
            return;
        }
        // check if verbose output
        if(args[3] == "-v1") {
            GLOBAL_verbose = 1;
        }
        pushto_parser(in_path, out_path);
    }
}

auto start = std::chrono::high_resolution_clock::now();
int main(int argc, char* argv[]) {
    if(std::string(MODE) == "DEV") {
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