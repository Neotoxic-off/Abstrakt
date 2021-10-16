#ifndef LOGS_HPP
    #define LOGS_HPP

    #include "required.hpp"

    #define TAB  "	"

    class Logs
    {
        public:
            std::map<int, std::string> map = {
                { 0x00, "trailing space at the end of the line" },
                { 0x01, "tabulation found" },
                { 0x02, "forbidden function found called: " },
                { 0x03, "too long line: " },
            };
    };


#endif /* LOGS_HPP */
