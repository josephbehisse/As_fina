#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

#include "Data_table.h"

typedef std::vector<std::vector<std::string>> matrix_string;

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

/**
 * @brief the class get an object of data and use those data to make a table
 * The class is able to clean unnecessary row and/or column in the table
 */
class Table_manager
{
private:
    /**
     * @brief contains the first row (header) of the table
     *
     */
    std::vector<std::string> m_header_box;

    /**
     * @brief contains the first column of the table (todo)
     *
     */
    std::vector<std::string> m_week_number_box;

    /**
     * @brief contains the all rows except the first row of the table
     *
     */
    matrix_string m_row_box_box;

    /**
     * @brief contains all rows of the table
     *
     */
    matrix_string m_table;

public:

    template <typename T>
    void print_test(T box_box); //tmp
    template <typename T>
    void print(T box); //tmp

    /**
     * @brief Construct a new Table_manager object
     *
     * @param obj object data that as to be use to contruct the table
     */
    Table_manager(Data_table &obj);

    /**
     * @brief Construct a new Table_manager object
     *
     * @param obj object data that as to be use to contruct the table
     * @param key character use to identify and clean unwanted row and column
     */
    Table_manager(Data_table &obj,  char *key);

    /**
     * @brief Create a table object
     *
     * @param header_box is the first row of the table object
     * @param data_box_box is the data row_box of the table object
     * @return matrix_string of data (return a table object)
     */
    matrix_string create_table(std::vector<std::string> &header_box, matrix_string &data_box_box);

    /**
     * @brief locate unwanted column
     *
     * @param table
     * @param key character to use to locate the column
     * @return std::vector<unsigned int> array of location (where to find the unwanted column)
     */
    std::vector<unsigned int> location_ignore_colum (matrix_string &table, char *key);

    /**
     * @brief locate unwanted row
     *
     * @param table
     * @param key character to use to locate the row
     * @return std::vector<unsigned int> array of location (where to find the unwanted row)
     */
    std::vector<unsigned int> location_ignore_row (matrix_string &table, char *key);

    /**
     * @brief remove (delete) all unwanted column
     *
     * @param table
     * @param key character to use to locate the column
     * @return matrix_string a new table
     */
    matrix_string remove_colum (matrix_string &table, char *key);

    /**
     * @brief remove (delete) all unwanted row
     *
     * @param table
     * @param key character to use to locate the row
     * @return matrix_string a new table
     */
    matrix_string remove_row (matrix_string &table, char *key);
};

#endif