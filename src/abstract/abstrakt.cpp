#include "abstrakt.hpp"

abstrakt::abstrakt(int ac_, char **argv_)
{
    this->ac = ac_;
    this->argv = argv_;
    this->line_number = 0;
    this->total_lines = 0;

    abstrakt::display_banner();
    abstrakt::build();
}

abstrakt::~abstrakt()
{
    return;
}

bool abstrakt::display_banner()
{
    for (auto i = this->banner.begin(); i != this->banner.end(); i++) {
        std::cout << this->colors.colors["magenta"] << *i << this->colors.colors["reset"] << std::endl;
    }
    std::cout << "\n" << std::endl;

    return (true);
}

bool abstrakt::build()
{
    if (abstrakt::check_args() == true) {
        abstrakt::load();
        abstrakt::parse();
        abstrakt::display_errors();
    }

    return (false);
}

bool abstrakt::check_args()
{
    if (ac == 2)
        return (true);
    return (false);
}

bool abstrakt::load()
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

bool abstrakt::report_error(std::string type_data)
{
    this->reported.data.push_back(type_data);
    this->reported.line.push_back(this->line_number);

    return (true);
}

bool abstrakt::parse()
{
    for (auto i = this->lines.begin(); i != this->lines.end(); i++, this->line_number++) {
        this->current_line = *i;
        abstrakt::scan_spaces();
        abstrakt::scan_tabs();
        abstrakt::scan_functions();
        abstrakt::scan_line_length();
    }

    return (true);
}

bool abstrakt::display_errors()
{
    std::size_t count = this->reported.line.size();
    std::size_t padding = std::to_string(this->reported.line.at(count - 1)).size();
    auto line_index = this->reported.line.begin();
    auto data_index = this->reported.data.begin();

    for (; line_index != this->reported.line.end(); line_index++, data_index++) {
        std::cout << this->colors.colors["blue"] << "line " << std::setw(static_cast<int>(padding)) << *line_index << ": " << *data_index << this->colors.colors["reset"] << std::endl;
    }

    std::cout << this->colors.colors["red"] << "\nTotal Errors: " << this->reported.data.size() << this->colors.colors["reset"] << std::endl;

    return (true);
}
