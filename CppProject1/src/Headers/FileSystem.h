#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class FileSystem
{

public:

    void writeFileStr(std::string filename, const char* str);

    void readFile(std::string filename, std::string& ReadBuffer);
};
