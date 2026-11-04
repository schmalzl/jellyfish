#include <iostream>
#include "../definitions.h"
#include <filesystem>
#include <string>
#include <sstream>

std::string get_target() {
    std::ostringstream target;

#if defined(__aarch64__) || defined(_M_ARM64)
    target << "arm64";
#elif defined(__x86_64__) || defined(_M_X64)
    target << "x86_64";
#elif defined(__i386__) || defined(_M_IX86)
    target << "i386";
#elif defined(__arm__) || defined(_M_ARM)
    target << "arm";
#else
    target << "unknown";
#endif

#if defined(__APPLE__)
    target << "-apple-darwin" << __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__;
#elif defined(__linux__)
    target << "-unknown-linux-gnu";
#elif defined(_WIN32)
    target << "-pc-windows-msvc";
#else
    target << "-unknown-unknown";
#endif

    return target.str();
}

void show_version() {
    std::cout << "jellyfish version " << VERSION << " (" << STD << ")" << std::endl;
    std::cout << "Target: " << get_target() << std::endl;
    std::cout << "InstalledDir: ";
    std::cout << std::filesystem::current_path() << '\n';
    std::cout << " " << std::endl;
}