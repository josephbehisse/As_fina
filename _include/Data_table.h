#ifndef DATA_TABLE
#define DATA_TABLE

//#include "Data_manager.h"

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

/**
 * @brief the class create a table and put all data in a box
 * I think this class will replace Data_manager class
 */
class Data_table
{
private:
   /**
 * @brief all the data will be store in one boxe for further process
 *
 */
   std::vector<std::string> m_box;

   /**
 * @brief
 *
 */
   std::vector<std::string> m_clean_box;

   /**
 * @brief will contains all weeks number
 *
 * @return a box of weeks number //todo actually a char of two character max
 */
   std::vector<std::string> m_week_nummer;

   /**
 * @brief will contains all week_data's number
 *
 * @return a box of week_data's
 */
   std::vector<std::string> m_week_data;

   /**
 * @brief will contains all week_data's number
 *
 * @return a box of week_data's
 */
   std::string m_header;

   /**
 * @brief
 *
 */
   std::vector<std::string> m_clean_header;

public:
   Data_table(std::vector<std::string> &box);
   std::string get_header();
   std::vector<std::string> get_header_box();

   /**
     * @brief Get all weeks numbers (all first item of week_data)
     *
     * @return std::vector<int>
     */
   std::vector<std::string> get_week_number_box();

   /**
     * @brief Get a specifiek string weeks numbers data
     *
     * @param week_number the specifiek "week" where to get the data
     *
     * @return std::string data
     */
   std::string get_spec_weeknumber(const std::string &week_number);

   /**
     * @brief Get week_item_data
     *
     * @param Item  remenber a header is a composition of items
     *
     * @return std::vector<int> week_item_data
     */
   float get_week_item_data(int week_number, std::string &Item);

   std::string get_item_data(std::string &Input);

   /**
     * @brief find and locate the input of the user in the header boxe
     *
     * @param item the specifiek "item" to be found
     *
     * @return the location of the item
     */
   const unsigned int locate_item(const std::string &item);

   std::vector<std::string> create_data_box(const std::string& input_data);
   std::vector<std::string>  get_week_data_box( const std::string& week_nummer);
   std::string get_week_item_data(const std::string &item_input, const std::string &week_input);
   std::vector<std::string> get_item_data_box(const std::string& item_input);
   std::vector<std::vector<std::string>> get_week_data_box_box();
   std::vector<std::string> get_year_data_box();
};

#endif // DATA_TABLE


/*


,-----------------------------------,
|Wk | item  | item  | item  | ###__ |  ---->  get_header_box()
------------------------------------|
|Wn | w_i_d | w_i_d | w_i_d | w_i_d |  ---->  get_week_data_box(Wn)
------------------------------------|
|Wn | w_i_d | w_i_d | w_i_d | w_i_d |
------------------------------------|
|Wn | w_i_d | w_i_d | w_i_d | w_i_d |
|-----------------------------------|
|#n | #_i_# | #_i_# | #_i_# | #_i_# |
'-----------------------------------'
  |              |
  |              |
  |              |
  |              '-----> this->get_item_data_box(item)
  |
  |
  '---> this->get_week_number_box()


Wn = Weeknummer

w_i_d = get_week_item_data(item, Wn)

location of w_i_d => locate_item(item)


*/