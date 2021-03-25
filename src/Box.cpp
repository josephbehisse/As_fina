#include "Box.h"

Box::Box()
{
	std::cout << "________________________welcome___________________";
	std::cout << std::endl;
	std::cout << std::endl;
}


std::vector<std::string> Box::init(File_X &myfile)
{
	bool valide_input = false;
	std::string user_input;
	while (!valide_input)
	{
		std::cout << "Enter your file name: ";
		std::cin >> user_input;
		std::cout << "Box data is shown " << user_input << std::endl;
		valide_input = myfile.open_file(user_input);

		if (user_input == "EXIT" || user_input == "exit")
		{
			return m_data;
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "__________________________________________________" << std::endl;
		std::cout << "enter EXIT to stop the program or " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << "________________Open file succeed_____________________" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	m_data = myfile.read_data(user_input);
	auto result = m_data;
	return result;
}