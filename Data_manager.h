#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

class Datamanager
{
private:
std::vector<std::string> m_box;
std::vector<int> m_week_nummer;
std::vector<std::string> m_week_data;
std::string m_header;
public:
    Datamanager(std::vector<std::string>& box);
    std::string get_header();
    std::vector<std::string> get_header_box();
    std::string find_item(std::string& Input);
    std::vector<int> grep_all_weeknumber();
    std::string get_spec_weeknumber(int week_number);
    float get_week_item_data(int week_number, std::string &Item);
    void testme();
    std::vector<float> get_week_data_box(const int weeknummer);
};

#endif // !DATA_MANAGER_H
