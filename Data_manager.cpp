#include "Data_manager.h"
#include <algorithm>

typedef std::vector<int>::size_type my_size_type;




Datamanager::Datamanager(std::vector<std::string>& box)
{
	m_box = box;
	for (my_size_type i = 0; i != m_box.size(); i++)
	{
		if(i == 0)
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
		auto temp_data =  data;
		auto temp = std::stoi(temp_data.erase(temp_data.find(";"))); // Todo when you convert to string check if you have a char like 'o' what will happen
		m_week_nummer.push_back(temp);
	}

}

std::string Datamanager::get_header()
{
	return m_header;
}

std::vector<std::string> Datamanager::get_header_box()
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

std::string Datamanager::find_item (std::string& Input)
{
	std::string delimiter = Input;
	size_t ref = 0;
	auto tmp_header = m_header;
	ref = tmp_header.find(delimiter);
	std::string result = tmp_header.substr(ref, tmp_header.size());
	result.erase(result.find(";"));
	return result;
}

std::vector<int> Datamanager::grep_all_weeknumber ()
{
	return m_week_nummer;
}

std::string Datamanager::get_spec_weeknumber(int week_number)
{
	for (auto &data : m_week_data)
	{
		auto tmp_data = data;
		auto my_week = std::stoi(tmp_data.erase(tmp_data.find(";")));
		if (my_week == week_number)
		{
			return data; //4; ? 323,00 ; ? 3,00 ; ? 5,00 ; ? 5,00 ; ? 5,00 ; ? 78,00 ; ? 78,00 ;;;;;;;;;;;;;;;
		}
	}
	return "";
}

// std::vector<int> Datamanager::get_week_data (std::string& week_number)
// {
// 	std::vector<int> result;
// 	return result;
// }

float Datamanager::get_week_item_data(int week_number, std::string& Item)
{
	std::string header = m_header;
	std::string data_ = this->get_spec_weeknumber(week_number);
	size_t pos_ref = 0;
	size_t ref_item_data = 0;
	size_t length_of_week_item_data = 0;
	auto ref = header.find(Item);
	std::string result = header.substr(0, ref + Item.length() +1 );
	size_t count_ref = std::count(result.begin(), result.end(), ';');

	for (auto &i : data_)
	{
		length_of_week_item_data++;
		ref_item_data++;
		if (i == ';')
		{
			pos_ref++;
			if (pos_ref ==  count_ref)
			{
				// std::string result_ = data_.substr(0, ref_item_data ); //use it to understand this algorithm beter
				size_t start_pos_triming = ref_item_data -length_of_week_item_data;
				std::string result = data_.substr(start_pos_triming, length_of_week_item_data - 1 );
				std::replace(result.begin(), result.end(), ',', '.');
				if(result == "")
					result = "0";
				return std::stof(result);
			}
			length_of_week_item_data = 0;
		}
	}
	return 0;
}


//todo
// you give 2 input (weeknummer and header) and you got the item data as output
void Datamanager::testme()
{
	auto header_data = this->get_header_box();
	std::vector<float> mydata;
	size_t i = 0;
	float header_value = 0.0;

	for (auto &data : header_data)
	{
		if ( i != 0)
			mydata.push_back(this->get_week_item_data(7, data));
		std::cout << "data =>>" << data  << std::endl;
		i++;
	}

	for (auto &value : mydata)
	{
		header_value += value;
		std::cout << "data =>>>>" << value  << std::endl;
		std::cout << "value =>>>>" << header_value  << std::endl;
	}

}

// 		Wk;E1;E2;E3;E4;E5;E6;E7;E8;E9;E10;E11;E12;E13;E14;E15;E16;E17;E18;E19;E20;E21;
// 		1;;;;;;;;;;;;;;;;;;;;;;
// 		2;;;;;;;;;;;;;;;;;;;;;;
// 		3;;;;;;;;;;;;;;;;;;;;;;
// 		4; ? 323,00 ; ? 3,00 ; ? 5,00 ; ? 5,00 ; ? 5,00 ; ? 78,00 ; ? 78,00 ;;;;;;;;;;;;;;;
// 		5; ? 3,00 ; ? 3,00 ; ? 3,00 ; ? 5,00 ; ? 5,00 ; ? 77,00 ; ? 4,00 ;;;;;;;;;;;;;;;
// 		6; ? 3,00 ; ? 23,00 ; ? 5,00 ; ? 5,00 ; ? 5,00 ; ? 67,00 ; ? 527,00 ;;;;;;;;;;;;;;;
// 		7; ? 8,00 ; ? 6,00 ; ? 4,00 ; ? 88,00 ; ? 5,00 ; ? 555,00 ; ? 6,00 ;;;;;;;;;;;;;;;
// 		8;;;;;;;;;;;;;;;;;;;;;;





std::vector<float> Datamanager::get_week_data_box(const int weeknummer)
{
    auto header_data = this->get_header_box();
    std::vector<float> mydata;
    size_t i = 0;
    float header_value = 0.0;

	for (auto &data : header_data)
	{
		mydata.push_back(this->get_week_item_data(weeknummer, data));
		i++;
	}
    return mydata;
}