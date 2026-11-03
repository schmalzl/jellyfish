#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <filesystem>

bool jfcompress(
    const std::string& template_path,
    const std::string& input_path,
    const std::string& output_path);