#include <iostream>
#include "../globals.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

void pushto_parser(std::string input, std::string output) {
    std::string content;
    if(GLOBAL_verbose == 1) {
        std::cout << "MODE verbose" << std::endl;
    }

    // check if file exists
    if(GLOBAL_verbose == 1) {
        std::cout << "[ INFO ] Verifying source file location." << std::endl;
    }
    if (!std::filesystem::exists(input)) {
        // no use of exceptions.h here since exceptions.h is only for argument errors.
        // errors in parsing / compression stage will be handles by a jfexcep.h
        // file handling errors will be outputted manually
        std::cerr << "[ FATAL ] Specified source file does not exist.\n";
        return;
    }
    // Check if the path actually points to a file
    if(GLOBAL_verbose == 1) {
        std::cout << "[ INFO ] Verifying source file path." << std::endl;
    }
    if (!std::filesystem::is_regular_file(input)) {
        std::cerr << "[ FATAL ] Specified path is not a regular file.\n";
        return;
    }

    if(GLOBAL_verbose == 1) {
        std::cout << "[ INFO ] Opening source file." << std::endl;
    }
    std::ifstream file(input, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "[ FATAL ] Unable to open source file.\n";
        return;
    }

    if(GLOBAL_verbose == 1) {
        std::cout << "[ INFO ] Reading source file." << std::endl;
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    if (file.bad()) {
        std::cerr << "[ FATAL ] Failed while reading file.\n";
        return;
    }

    content = buffer.str();
    file.close();
    std::cout << "[ OK ] Read from source file." << std::endl;
    if(GLOBAL_verbose == 1) {
        std::cout << "[ INFO ] Transfering content to parser." << std::endl;
    }

    // send content to analyser
}