#ifndef RAW_DATA_H
#define RAW_DATA_H


#include "Entry.h"


#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif


class Raw_data : public Entry
{

public:
	Raw_data();
	std::vector<std::string> read_data() override;
};

#endif // !RAW_DATA_H
