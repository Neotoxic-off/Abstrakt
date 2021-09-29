#include "abstract.hpp"

#include "types.hpp"

abstract::abstract(int ac, char **argv)
{
    this->ac = ac;
    this->argv = argv;
    this->line_number = 0;
    this->total_lines = 0;

    abstract::build();
}

abstract::~abstract()
{
    return;
}

bool abstract::build()
{
    if (abstract::check_args() == true) {
        abstract::load();
        abstract::parse();
        abstract::display_errors();
    }

    return (false);
}

bool abstract::check_args()
{
    if (ac == 2)
        return (true);
    return (false);
}

bool abstract::load()
{
    std::ifstream infile(this->argv[1]);
    std::string line;

    if (infile.is_open()) {
        while(getline(infile, line))
            this->lines.push_back(line);
        infile.close();
        this->total_lines = this->lines.size();
    }
    return (true);
}

bool abstract::scan_spaces()
{
    size_t size = this->current_line.size();

    if (size > 0) {
        if (this->current_line[size - 1] == ' ') {
            abstract::report_error(TRAILING_SPACE);
            return (true);
        }
    }

    return (false);
}

bool abstract::scan_tabs()
{
    size_t size = this->current_line.length();

    if (size > 0) {
        for (size_t i = 0; i < size; i++) {
            if (this->current_line[i] == TAB[0]) {
                abstract::report_error(TRAILING_TAB);
                return (true);
            }
        }
    }

    return (false);
}

bool abstract::report_error(std::string type_data)
{
    this->report_data.insert(std::pair<std::string, size_t>(type_data, this->line_number));

    return (true);
}

bool abstract::parse()
{
    for (auto i = this->lines.begin(); i != this->lines.end(); i++, this->line_number++) {
        this->current_line = *i;
        abstract::scan_spaces();
        abstract::scan_tabs();
    }

    return (true);
}

bool abstract::display_errors()
{
    std::string display_line_label = "line: ";
    size_t line_size = std::to_string(this->total_lines).size() + 1;
    size_t previous = 0;

    for (auto i = this->report_data.begin(); i != this->report_data.end(); i++) {
        if (i->second != previous) {
            previous = i->second;
            std::cout << display_line_label << previous << std::endl;
        }
        std::cout << "\t" << i->first << std::endl;
    }

    std::cout << std::endl << this->report_data.size() << " error(s) for " << this->lines.size() << " lines" << std::endl;
    
    return (true);
}

std::string abstract::set_line(size_t size)
{
    std::string line = "";

    for (size_t i = 0; i < size; i++)
        line += '-';

    return (line);
}