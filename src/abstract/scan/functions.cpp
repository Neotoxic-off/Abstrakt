#include "abstrakt.hpp"

#include "exclusions.hpp"

bool abstrakt::scan_functions()
{
    size_t size = this->current_line.length();

    if (size > 0) {
        for (auto i = this->exclution.functions.begin(); i != this->exclution.functions.end(); i++) {
            if (this->current_line.find(*i) != std::string::npos) {
                abstrakt::report_error(
                    this->logs.map[0x02].append(*i)
                );
                return (true);
            }
        }
    }

    return (false);
}
