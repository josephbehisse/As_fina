#include "Table_manager.h"
#include "Sort.h"

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
    // this->print_test(m_table);

    //remove colum
    auto colum_location = this->location_ignore_colum(m_table, key);
    m_table = this->remove_colum(m_table, key);

    //remove row
    m_table = this->remove_row(m_table, key);


    // this->print(location_ignore_row(m_table, key));
    this->print_test(m_table);
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





//don't know why I need this  => deleled ?
// matrix_string Table_manager::get_spec_row_box_box(Data_table &obj, const unsigned int row_number)
// {
//     auto tmp_tab = m_table;
//     auto row = tmp_tab;
//     std::vector<std::vector<std::string>> spec_row_box_box;
//     for (int i = 0; i < row.size(); i++)
//     {
//         if (i == row_number)
//         {
//             spec_row_box_box.push_back(row[i]);
//             return spec_row_box_box;
//         }
//     }
//     //Error //
//     return spec_row_box_box;
// }



template <typename T>
void Table_manager::print_test(T box_box)
{
    std::cout << "___________print()_____________" << std::endl;
    for (auto &box : box_box)
    {
        for (auto &data : box)
        {
            std::cout << " " << data << " |";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Table_manager::print(T box)
{
    std::cout << "___________print()_____________" << box.size() << std::endl;

    for (auto &data : box)
    {
        std::cout << " " << data << " |";
    }
    std::cout << std::endl;
}