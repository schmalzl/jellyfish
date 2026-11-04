#include <iostream>
using std::cout; using std::string; using std::endl;
#include "message.h"

void throw_noinputexcep() {
    push_status("FATAL", "No input.");
}

void throw_nooutputpath() {
    push_status("FATAL", "No output path specified.");
}