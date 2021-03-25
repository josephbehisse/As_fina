#include "Print.h"

Print::Print()
{
}


void Print::print_table(Table_manager &table)
{
    auto box_box = table.get_table();
    TextTable t('-', '|', '+');

    std::cout << "___________print()_____________" << std::endl;
    for (auto &box : box_box)
    {
        for (auto &data : box)
        {
            t.add(data);
        }
        t.endOfRow();
    }
    t.setAlignment(2, TextTable::Alignment::RIGHT);
    std::cout << t;
}
