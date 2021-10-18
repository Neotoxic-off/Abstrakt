#ifndef TYPES_HPP
    #define TYPES_HPP

    #include "required.hpp"
    
    class Types
    {
        public:
            std::vector<std::string> types = {
                "void",
                "int",
                "char",
                "float",
                "unsigned char",
                "unsigned int",
                "short",
                "unsigned short",
                "long",
                "unsigned long",
                "size_t",
                "double",
                "long double",
                "const",
                "typedef",
                "struct"
            };

            bool is_type(std::string);
    };

#endif /* TYPES_HPP */
