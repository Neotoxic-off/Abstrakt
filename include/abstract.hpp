#ifndef ABSTRACT_HPP
    #define ABSTRACT_HPP

    #include "required.hpp"
    #include "logs.hpp"
    #include "types.hpp"

    #define TAB  "	"

    class abstract
    {
        public:
            abstract(int, char **);
            ~abstract();

        private:
            bool build();
            bool load();
            bool check_args();
            bool parse();
            bool report_error(std::string);
            bool display_errors();
            bool display_banner();

            bool scan_spaces();
            bool scan_tabs();
            bool scan_functions();

            // args
            int ac;
            char **argv;

            // settings
            char *file;
            size_t total_lines;

            // data
            size_t errors;
            size_t line_number;
            std::string current_line;
            std::vector<std::string> lines;
            std::vector<std::string> banner = {
                "Abstrakt",
                "Author:  Neotoxic-off",
                "Version: 1.0.0"
            };
            
            struct report
            {
                std::vector<std::string> data;
                std::vector<std::size_t> line;
            };

            report reported;
    };

#endif /* ABSTRACT_HPP */
