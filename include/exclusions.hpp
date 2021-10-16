#ifndef EXCLUSIONS_HPP
    #define EXCLUSIONS_HPP

    #include "required.hpp"

    class Exclusions
    {
        public:
            std::size_t line_limit = 80;
            std::vector<std::string> functions = {
                "printf",
                "scanf",
                "memcpy",
                "memset",
                "memmove",
                "strcat",
                "strchar",
                "strcpy",
                "atoi",
                "strlen",
                "strstr"
                "strncat",
                "strncpy",
                "strcmp",
                "strncmp",
                "strtok",
                "strnlen",
                "strdup",
                "realloc"
            };
    };

#endif /* EXCLUSIONS_HPP */
