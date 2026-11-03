#include <iostream>

void push_text(std::string text) {
    std::cout << text << std::endl;
}

void push_status(std::string status, std::string message) {
    std::cout << "[ " << status << " ] " << message << std::endl;
}