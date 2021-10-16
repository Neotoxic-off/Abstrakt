#include "abstrakt.hpp"

bool abstrakt::scan_spaces()
{
    size_t size = this->current_line.size();

    if (size > 0) {
        if (this->current_line[size - 1] == ' ') {
            abstrakt::report_error(
                this->logs.map[0x00]
            );
            return (true);
        }
    }

    return (false);
}
