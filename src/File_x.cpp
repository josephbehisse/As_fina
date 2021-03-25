#include "File_x.h"

File_X::File_X()
{
}

bool File_X::open_file(const std::string& filename)
{
	m_file.open(filename);
	if (!m_file.is_open())
    {
        std::cout << std::endl;
		std::cout << std::endl;
        std::cout << "Unable to open file \n";
        std::cout << std::endl;
		std::cout << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> File_X::read_data(const std::string& filename)
{
    std::vector<std::string> boxes;
    std::string data_by_line;

    while (std::getline(m_file, data_by_line))
    {
        data_by_line.erase(std::remove(data_by_line.begin(), data_by_line.end(), ' '), data_by_line.end());
        data_by_line.erase(std::remove(data_by_line.begin(), data_by_line.end(), '_'), data_by_line.end());
        data_by_line.erase(std::remove(data_by_line.begin(), data_by_line.end(), '-'), data_by_line.end());
        boxes.push_back(data_by_line);
    }
    m_file.close();
    return boxes;
}