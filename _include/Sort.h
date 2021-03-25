#ifndef SORT_H
#define SORT_H


#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif
/**
 * @brief Sorting a vector in descending order
 * ref: https://stackoverflow.com/questions/9025084/sorting-a-vector-in-descending-order
 */
struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

#endif