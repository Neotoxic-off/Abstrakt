#ifndef ABSTRACT_HPP
    #define ABSTRACT_HPP

    #include "required.hpp"
    #include "logs.hpp"
    #include "exclusions.hpp"
    #include "report.hpp"
    #include "colors.hpp"

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

            // struct
            report reported;

            // variables
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
                    " _____ _       _           _   _   ",
                    "|  _  | |_ ___| |_ ___ ___| |_| |_ ",
                    "|     | . |_ -|  _|  _| .'| '_|  _|",
                    "|__|__|___|___|_| |_| |__,|_,_|_|  ",
                };

            // functions
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
            bool scan_line_length();
    };

#endif /* ABSTRACT_HPP */
