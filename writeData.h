#pragma once
#include <fstream>
#include <vector>

#include "readData.h"

class writeData {
public:
    writeData(const std::string& output_file);
    void writeIntoFile(const std::vector<object>& elements, int need_count);
    ~writeData();
private:
    std::ofstream output;
};
