#include "reader.hpp"


dd::file::~file()
{
    if (filestream.is_open()) 
    {
        filestream.close();
    }
}

bool dd::file::open() noexcept
{
    try {
        filestream.open(filepath);
    }
    catch (...) {
        return false;
    }
    return true;
}

void dd::file::read_all()
{
    if (filestream.is_open())
    {
        for (std::string line; std::getline(filestream, line); )
        {
            if (header::is_header(line)) {

            } 
            else if (data::is_data(line)) {

            }
            else if (footer::is_footer(line)) {

            }
        }
    }
}
