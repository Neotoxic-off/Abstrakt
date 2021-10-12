#include "abstract.hpp"

bool abstract::scan_tabs()
{
    size_t size = this->current_line.length();

    if (size > 0) {
        for (size_t i = 0; i < size; i++) {
            if (this->current_line[i] == TAB[0]) {
                abstract::report_error(TRAILING_TAB);
                return (true);
            }
        }
    }

    return (false);
}
