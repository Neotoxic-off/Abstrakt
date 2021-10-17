#ifndef ABSTRACT_HPP
    #define ABSTRACT_HPP

    #include "required.hpp"
    #include "logs.hpp"
    #include "exclusions.hpp"
    #include "report.hpp"
    #include "colors.hpp"
    #include "types.hpp"

    class abstrakt
    {
        public:
            abstrakt(int, char **);
            ~abstrakt();

        private:
            // class
            Logs logs;
            Colors colors;
            Exclusions exclution;
            Types types;

            // struct
            report reported;

            // variables
                // args
                int ac;
                char **argv;

                // settings
                char *file;
                std::size_t total_lines;

                // data
                std::size_t errors;
                std::size_t line_number;
                std::size_t function_number;

                std::string current_line;
                std::vector<std::string> lines;
                std::vector<std::string> banner = {
                    " _____ _       _           _   _   ",
                    "|  _  | |_ ___| |_ ___ ___| |_| |_ ",
                    "|     | . |_ -|  _|  _| .'| '_|  _|",
                    "|__|__|___|___|_| |_| |__,|_,_|_|  ",
                };

            // functions
                // tools
                bool build();
                bool load();
                bool check_args();
                bool parse();
                bool report_error(std::string);
                bool display_errors();
                bool display_banner();

                // scan
                bool scan_spaces();
                bool scan_tabs();
                bool scan_functions();
                bool scan_line_length();
                bool count_functions();
    };

#endif /* ABSTRACT_HPP */
