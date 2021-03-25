#include "Data_table.h"

typedef std::vector<int>::size_type my_size_type;

Data_table::Data_table(std::vector<std::string> &box)
{
	m_box = box;
	for (my_size_type i = 0; i != m_box.size(); i++)
	{
		if (i == 0)
		{
			m_header = m_box[i];
		}
		if (i != 0)
		{
			m_week_data.push_back(m_box[i]);
		}
	}

	for (auto &data : m_week_data)
	{
		auto temp_data = data;
		auto temp = temp_data.erase(temp_data.find(";"));
		m_week_nummer.push_back(temp);
	}
}

std::string Data_table::get_header()
{
	return m_header;
}

std::vector<std::string> Data_table::create_data_box(const std::string &input_data)
{
	std::vector<std::string> data_box;
	auto my_data = input_data;
	size_t length_of_week_item_data = 0;
	size_t start_pos_triming = 0;

	for (auto &i : my_data)
	{
		length_of_week_item_data++;
		if (i == ';')
		{
			std::string item_data = my_data.substr(start_pos_triming, length_of_week_item_data - (1 + start_pos_triming));
			data_box.push_back(item_data);
			start_pos_triming = length_of_week_item_data;
		}
	}
	return data_box;
}

std::vector<std::string> Data_table::get_header_box()
{
	std::vector<std::string> item_box;
	std::string my_header = this->get_header();
	size_t length_of_week_item_data = 0;
	size_t start_pos_triming = 0;

	for (auto &i : my_header)
	{
		length_of_week_item_data++;
		if (i == ';')
		{
			std::string item_header = my_header.substr(start_pos_triming, length_of_week_item_data - (1 + start_pos_triming));
			item_box.push_back(item_header);
			start_pos_triming = length_of_week_item_data;
		}
	}
	return item_box;
}

std::vector<std::string> Data_table::get_week_number_box()
{
	return m_week_nummer;
}

std::string Data_table::get_spec_weeknumber(const std::string &week_number)
{
	for (auto &data : m_week_data)
	{
		auto tmp_data = data;
		auto my_week = tmp_data.erase(tmp_data.find(";"));
		if (!my_week.compare(week_number))
		{
			return data;
		}
	}
	return "";
}

std::vector<std::string> Data_table::get_year_data_box()
{
	std::vector<std::string> my_year_data_box;
	auto all_weeknumber = this->get_week_number_box();

	for (auto &week_number_box : all_weeknumber)
	{
		auto week_string = this->get_spec_weeknumber(week_number_box);
		auto year_data_box = this->create_data_box(week_string);
		for (auto &my_data : year_data_box)
		{
			my_year_data_box.push_back(my_data);
		}
	}
	return my_year_data_box;
}

const unsigned int Data_table::locate_item(const std::string &item)
{
	auto my_header_box = this->get_header_box();
	int Item_location = 0;

	for (auto &data : my_header_box)
	{
		Item_location++;
		if (!data.compare(item))
		{
			return Item_location;
		}
	}
	return 0;
}

std::vector<std::string> Data_table::get_week_data_box(const std::string &week_nummer)
{
	auto tmp_data = this->get_spec_weeknumber(week_nummer);
	auto week_data = this->create_data_box(tmp_data);
	return week_data;
}

std::string Data_table::get_week_item_data(const std::string &item_input, const std::string &week_input)
{
	auto week_number_box = this->get_week_number_box();
	auto item_location = this->locate_item(item_input);

	if (item_location == 0)
	{
		//item_input doesn't exit
		return "item error";
	}

	for (auto &wn_exit : week_number_box)
	{
		if (!wn_exit.compare(week_input))
		{
			auto databox = this->get_week_data_box(wn_exit);
			std::string week_item_data = databox[item_location - 1];
			return week_item_data;
		}
	}
	//week_input doesn't exit
	return "week error";
}

std::vector<std::string> Data_table::get_item_data_box(const std::string &item_input)
{
	auto tmp_week_box = this->get_week_number_box();
	std::vector<std::string> item_data_box;
	for (auto &week_input : tmp_week_box)
	{
		auto item_data = this->get_week_item_data(item_input, week_input);
		item_data_box.push_back(item_data);
	}
	return item_data_box;
}

std::vector<std::vector<std::string>> Data_table::get_week_data_box_box()
{
	auto week_number_box = this->get_week_number_box();
	std::vector<std::string> week_data_box;
	std::vector<std::vector<std::string>> week_data_box_box;
	for (auto &wn : week_number_box)
	{
		week_data_box = this->get_week_data_box(wn);
		week_data_box_box.push_back(week_data_box);
	}
	return week_data_box_box;
}



