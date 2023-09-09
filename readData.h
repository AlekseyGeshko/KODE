#pragma once
#include <fstream>
#include <vector>

struct object{
    std::string name;
    std::string type;
    double time;
    double x;
    double y;
};

class readData final{
public:
    readData(const std::string& input_file);
    std::vector<object> getObjects();
    ~readData();
private:
    std::ifstream input;
};

