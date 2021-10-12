#include "abstract.hpp"

abstract::abstract(int ac, char **argv)
{
    this->ac = ac;
    this->argv = argv;
    this->line_number = 0;
    this->total_lines = 0;

    abstract::display_banner();
    abstract::build();
}

abstract::~abstract()
{
    return;
}

bool abstract::display_banner()
{
    for (auto i = this->banner.begin(); i != this->banner.end(); i++) {
        std::cout << *i << std::endl;
    }
    std::cout << std::endl;

    return (true);
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

bool abstract::report_error(std::string type_data)
{
    this->reported.data.push_back(type_data);
    this->reported.line.push_back(this->line_number);

    return (true);
}

bool abstract::parse()
{
    for (auto i = this->lines.begin(); i != this->lines.end(); i++, this->line_number++) {
        this->current_line = *i;
        abstract::scan_spaces();
        abstract::scan_tabs();
        abstract::scan_functions();
    }

    return (true);
}

bool abstract::display_errors()
{
    size_t line_size = std::to_string(this->total_lines).size() + 1;

    auto line_index = this->reported.line.begin();
    auto data_index = this->reported.data.begin();

    for (; line_index != this->reported.line.end(); line_index++, data_index++) {

        std::cout << "line: " << *line_index << " " << *data_index << std::endl;
    }

    return (true);
}
