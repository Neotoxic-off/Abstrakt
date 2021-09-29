#ifndef ABSTRACT_HPP
    #define ABSTRACT_HPP

    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <map>
    #include <string>
    #include <iterator>
    #include <iomanip>

    #define TRAILING_SPACE "trailing space at the end of the line"
    #define TRAILING_TAB "tabulation found on the line"

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
            bool scan_spaces();
            bool scan_tabs();
            bool parse();
            bool report_error(std::string);
            bool display_errors();

            std::string set_line(size_t);

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
            std::map<std::string, size_t> report_data;
    };

#endif /* ABSTRACT_HPP */
