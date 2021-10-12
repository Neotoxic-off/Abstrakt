#include "abstract.hpp"

bool abstract::scan_spaces()
{
    size_t size = this->current_line.size();

    if (size > 0) {
        if (this->current_line[size - 1] == ' ') {
            abstract::report_error(TRAILING_SPACE);
            return (true);
        }
    }

    return (false);
}