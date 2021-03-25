#include "Graph.h"
#include "Block_graph.h"
#include "Line_graph.h"
#include "File_x.h"
#include "Raw_data.h"
#include "Data_manager.h"
#include "Data_table.h"
#include "Box.h"
#include "Compute.h"
#include "Calendar.h"
#include "Print.h"
#include "Table_manager.h"

int main()
{
    Print p;

    File_X myfile;
    Box b;
    auto data = b.init(myfile);
    Data_table data_box(data);

    char key = '#';
    Table_manager tab(data_box, &key);
    p.print_table(tab);

    return 0;
}
