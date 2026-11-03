#include <iostream>
using std::cout; using std::string; using std::endl;
#include "message.h"

void throw_nullargexcep() {
    push_status("FATAL", "No input.");
}