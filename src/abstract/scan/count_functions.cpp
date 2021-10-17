#include "abstrakt.hpp"

#include "exclusions.hpp"

bool abstrakt::count_functions()
{
    size_t size = this->current_line.length();
    std::istringstream splitted(this->current_line);
    std::vector<std::string> results(
        std::istream_iterator<std::string>{splitted},
        std::istream_iterator<std::string>()
    );
    std::map<std::string, std::size_t> construction = {
        { "type", 0 },
        { "other", 0 },
        { "parenth_o", 0 },
        { "parenth_c", 0 }
    };

    if (size > 0) {
        for (auto i = results.begin(); i != results.end(); i++) {
            if (this->types.is_type(*i) == true) {
                construction["type"]++;
            } else {
                construction["other"]++;
                if (i->find("(") != std::string::npos) {
                    construction["parenth_o"]++;
                }
                if (i->find(")") != std::string::npos) {
                    construction["parenth_c"]++;
                }
            }
        }

        if (construction["other"] > 0 && construction["type"] > 0 && construction["parenth_o"] > 0 && construction["parenth_c"] > 0) {
            std::cout << "this is maybe a function:" << this->current_line << std::endl;
        }
    }

    return (false);
}
