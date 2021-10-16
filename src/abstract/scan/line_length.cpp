#include "abstrakt.hpp"

#include "exclusions.hpp"

bool abstrakt::scan_line_length()
{
    std::size_t size = this->current_line.length();
    std::string convert = std::to_string(size);

    if (size > this->exclution.line_limit) {
        abstrakt::report_error(
            this->logs.map[0x03].append(convert)
        );
        return (true);
    }

    return (false);
}
