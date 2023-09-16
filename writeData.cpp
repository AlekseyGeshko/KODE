#include "writeData.h"

#include <fstream>
#include <memory>
#include <vector>

#include "readData.h"
#include "groupBy.h"
#include "groupByDistance.h"
#include "groupByTime.h"
#include "groupByType.h"
#include "groupByName.h"

using namespace group;
using namespace std;

writeData::writeData(const string& output_file): output(output_file){}

void writeData::writeIntoFile(const std::vector<object>& elements, int need_count) {
    vector<unique_ptr<groupBy>> groups;
    groups.reserve(4);
    groups.push_back(make_unique<groupByType>(need_count));
    groups.push_back(make_unique<groupByName>());
    groups.push_back(make_unique<groupByTime>());
    groups.push_back(make_unique<groupByDistance>());
    for (const auto &elem: groups) {
        elem->group(elements);
        elem->printInFile(output);
    }
}

writeData::~writeData() {
    output.close();
}
