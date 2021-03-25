#include "Table_manager.h"
#include "Sort.h"
#include <iomanip>

Table_manager::Table_manager(Data_table &obj)
{
    //get data
    m_header_box = obj.get_header_box();
    auto header_box = m_header_box;
    m_row_box_box = obj.get_week_data_box_box();
    auto tmp_week_data_box_box = m_row_box_box;

    //create table
    std::cout << "________________CREATE TABLE_____________" << std::endl;
    m_table = this->create_table(header_box, tmp_week_data_box_box);
}

Table_manager::Table_manager(Data_table &obj, char *key)
{
    //get data
    m_header_box = obj.get_header_box();
    auto header_box = m_header_box;
    m_row_box_box = obj.get_week_data_box_box();
    auto tmp_week_data_box_box = m_row_box_box;

    //create table
    std::cout << "________________CREATE TABLE_____________" << std::endl;
    m_table = this->create_table(header_box, tmp_week_data_box_box);

    //remove colum
    auto colum_location = this->location_ignore_colum(m_table, key);
    m_table = this->remove_colum(m_table, key);

    //remove row
    m_table = this->remove_row(m_table, key);

}

matrix_string Table_manager::create_table(std::vector<std::string> &header_box, matrix_string &data_box_box)
{
    matrix_string table_result;
    table_result.push_back(header_box);
    for (auto &data_box : data_box_box)
    {
        table_result.push_back(data_box);
    }
    return table_result;
}

matrix_string Table_manager::get_table() const { return m_table;};


std::vector<unsigned int> Table_manager::location_ignore_colum(matrix_string &table, char *key)
{
    bool first_row = true;
    std::vector<unsigned int> colum_location_box;
    for (auto &box : table)
    {
        unsigned int colum_location = 0;
        if (first_row)
        {
            for (auto &data : box)
            {
                if (data[0] == *key)
                {
                    colum_location_box.push_back(colum_location);
                }
                colum_location++;
            }
        }
        first_row = false;
    }
    std::sort(colum_location_box.begin(), colum_location_box.end(), std::greater<>());
    return colum_location_box;
}

std::vector<unsigned int> Table_manager::location_ignore_row(matrix_string &table, char *key)
{
    unsigned int row_location = 0;
    std::vector<unsigned int> row_location_box;
    for (auto &box : table)
    {
        unsigned int i = 0;
        for (auto &data : box)
        {
            if (i == 0)
            {
                if (data[0] == *key)
                {
                    row_location_box.push_back(row_location);
                }
            }
            i++;
        }
        row_location++;
    }
    std::sort(row_location_box.begin(), row_location_box.end(), std::greater<>());
    return row_location_box;
}

matrix_string Table_manager::remove_row(matrix_string &table, char *key)
{
    auto row_location_box = this->location_ignore_row(table, key);
    for (auto &row_location : row_location_box)
    {
        table.erase(table.begin() + row_location);
    }
    return table;
}

matrix_string Table_manager::remove_colum(matrix_string &table, char *key)
{
    auto colum_ignore_box = this->location_ignore_colum(table, key);
    if (0 < colum_ignore_box.size())
    {
        for (auto &table_box : table)
        {
            for (auto &colum_ignore : colum_ignore_box)
            {
                table_box.erase(table_box.begin() + colum_ignore);
            }
        }
    }
    return table;
}

