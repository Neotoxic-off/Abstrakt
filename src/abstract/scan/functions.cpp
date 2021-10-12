#include "abstract.hpp"

#include "exclutions.hpp"

bool abstract::scan_functions()
{
    size_t size = this->current_line.length();

    if (size > 0) {
        for (auto i = exclutions::functions.begin(); i != exclutions::functions.end(); i++) {
            if (this->current_line.find(*i) != std::string::npos) {
                abstract::report_error(std::string(FORBIDDEN_FUNCTION).append(*i));
                return (true);
            }
        }
    }

    return (false);
}