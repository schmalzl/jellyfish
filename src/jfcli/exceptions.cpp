#include <iostream>
using std::cout; using std::string; using std::endl;
#include "message.h"

void throw_noinputexcep() {
    push_status("FATAL", "No input.");
}

void throw_filenotfoundexcep(std::string filename) {
    push_status("FATAL", "Cannot locate " + filename);
}

void throw_fileopenexcep(std::string filename) {
    push_status("FATAL", "Cannot read from " + filename);
    push_text("Make sure jellyfish has the appropriate rights to access the file.");
}