/*
  ==============================================================================
   This file is part of my HOBBY PROJECT.
   Copyright (c) 2021
   Author: Joseph Behisse
   Permission to use, copy, modify, and/or distribute this software for any purpose
   with or without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.
   The code IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.
  ==============================================================================
*/

#ifndef FILE_X_H
#define FILE_X_H


#include "Entry.h"
#include <fstream>


#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif
/**
 * @brief A class that represent a data stream to read
 *
 */
class File_X
{
private:
    /**
     * @brief the file to be read
     *
     */
    std::ifstream m_file;
public:
    /**
     * @brief Construct a new File_X object
     *
     */
    File_X();

    /**
     * @brief open a ascii file
     *
     * @param filename the filename to open
     */
    bool open_file(const std::string &filename);
    /**
     * @brief read the data of the file and erase some unnecessary ascii character
     *
     * @return std::vector<std::string> data as a boxe of data readable for this app
     */
    std::vector<std::string> read_data(const std::string& filename);
};

#endif // !FILE_X_H
