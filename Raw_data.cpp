#include "Raw_data.h"

Raw_data::Raw_data()
{
    std::string input_data;
	std::cout << "Enter your data en press enter " << std::endl;
    std::cin >>input_data;
    std::cout << "your input data is " << input_data << std::endl;
}

std::vector<std::string> Raw_data::read_data()
{
	std::cout <<"my read_data from RAW_DATA is showed" << std::endl;
    // std::getline (std::cin,output);
    std::vector<std::string> boxes;
    return boxes;
}