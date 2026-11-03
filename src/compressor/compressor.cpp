#include <cstdint>
#include <fstream>
#include <string>
#include <filesystem>

static constexpr char MAGIC[] = "PAYLOAD1";

bool jfcompress(
    const std::string& template_path,
    const std::string& input_path,
    const std::string& output_path)
{
    std::ifstream executable(template_path, std::ios::binary);
    std::ifstream input(input_path, std::ios::binary);

    if (!executable || !input)
        return false;

    std::ofstream output(
        output_path,
        std::ios::binary | std::ios::trunc
    );

    if (!output)
        return false;

    output << executable.rdbuf();

    if (!output)
        return false;

    input.seekg(0, std::ios::end);
    const auto size = input.tellg();

    if (size < 0)
        return false;

    input.seekg(0, std::ios::beg);

    const std::uint64_t payload_size =
        static_cast<std::uint64_t>(size);

    output << input.rdbuf();

    if (!output)
        return false;

    output.write(
        reinterpret_cast<const char*>(&payload_size),
        sizeof(payload_size)
    );

    output.write(MAGIC, sizeof(MAGIC) - 1);

    return static_cast<bool>(output);
}