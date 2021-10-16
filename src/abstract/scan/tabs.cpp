#include "abstrakt.hpp"

bool abstrakt::scan_tabs()
{
    size_t size = this->current_line.length();

    if (size > 0) {
        for (size_t i = 0; i < size; i++) {
            if (this->current_line[i] == TAB[0]) {
                abstrakt::report_error(
                    this->logs.map[0x01]
                );
                return (true);
            }
        }
    }

    return (false);
}
