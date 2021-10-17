#include "abstrakt.hpp"

bool Types::is_type(std::string type)
{
    for (auto i = this->types.begin(); i != this->types.end(); i++) {
        if (type == *i)
            return (true);
    }

    return (false);
}
