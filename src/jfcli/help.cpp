#include <iostream>

void show_help() {
    std::cout << "To return compiler information:" << std::endl;
    std::cout << "USAGE: jellyfishc <argument>" << std::endl;
    std::cout << "-v | -V | --version        SHOW VERSION INFORMATION" << std::endl;
    std::cout << "-h | -H | --help           SHOW HELP DIALOG" << std::endl;
    std::cout << "To compile a file:" << std::endl;
    std::cout << "USAGE: jellyfishc <inputfile_dir> -o <output_dir> (-v1)" << std::endl;
    std::cout << "-v1       VERBOSE COMPILER LOG" << std::endl;
    std::cout << "Note: Parts of the compiler command marked in parentheses are optional" << std::endl;
}