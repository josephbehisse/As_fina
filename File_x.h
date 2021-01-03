#ifndef FILE_X_H
#define FILE_X_H


#include "Entry.h"
#include <fstream>


#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

class File_X : public Entry
{
private:
    std::ifstream m_file;
public:
    File_X(const std::string &filename);
    std::vector<std::string> read_data() override;
};

#endif // !FILE_X_H
