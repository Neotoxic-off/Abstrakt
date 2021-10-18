#include "abstrakt.hpp"

bool abstrakt::scan_header()
{
    std::size_t size = this->current_line.length();
    std::array<std::string, 6> header = {
        "/*",
        "** EPITECH PROJECT, ",
        "** ",
        "** File description:",
        "** ",
        "*/"
    };

    if (size > 0) {
        if (this->line_number <= header.size()) {
            if (this->current_line.find(header[this->line_number]) == std::string::npos) {
                abstrakt::report_error(
                    this->logs.map[0x04]
                );
                return (true);
            }
        }
    }

    return (false);
}
