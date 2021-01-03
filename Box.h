#ifndef BOX_H
#define BOX_H

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif

/**
 *
 * This class create "your comment here"
 *
 */
class Box
{
private:
/**
 * @brief "your comment here"
 *
 * @return "your comment here"
 */
    std::vector<int> data;
public:
/**
 * @brief Construct a new Box object
 *
 * @param data_line "your comment here"
 */
    Box(std::string data_line);
    /**
     * @brief "your comment here"
     * 
     */
    void show_data();
};

#endif // !DATA_MANAGER_H