#ifndef BOX_H
#define BOX_H

#include "File_x.h"

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

class Box
{
private:
    std::vector<int> data;
    std::vector<std::string> m_data;
public:
    Box();
    /**
     * @brief
     *
     * @param myfile
     * @return std::vector<std::string>
     */
    std::vector<std::string>  init(File_X &myfile);
};

#endif