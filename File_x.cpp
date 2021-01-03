#include "File_x.h"

File_X::File_X(const std::string& filename)
{
	m_file.open(filename);
	if (!m_file.is_open())
    {
        std::cout << "Unable to open file \n";
        return;
    }
}

std::vector<std::string> File_X::read_data()
{
    std::vector<std::string> boxes;
    std::string data_by_line;

    while (std::getline(m_file, data_by_line))
    {
        data_by_line.erase(std::remove(data_by_line.begin(), data_by_line.end(), ' '), data_by_line.end());
        data_by_line.erase(std::remove(data_by_line.begin(), data_by_line.end(), '?'), data_by_line.end());
        boxes.push_back(data_by_line);
    }
    return boxes;
}