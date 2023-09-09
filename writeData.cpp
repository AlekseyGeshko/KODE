#include "writeData.h"

#include <fstream>
#include <vector>

#include "readData.h"
#include "groupBy.h"
#include "groupByDistance.h"
#include "groupByTime.h"
#include "groupByType.h"
#include "groupByName.h"

using namespace group;

writeData::writeData(const std::string& output_file): output(output_file){}

void writeData::writeIntoFile(const std::vector<object>& elements, int need_count) {
    std::vector<groupBy *> groups = {new groupByType(need_count),
                                     new groupByName(), new groupByTime(),
                                     new groupByDistance()};
    for (const auto &elem: groups) {
        elem->group(elements);
        elem->printInFile(output);
    }
}

writeData::~writeData() {
    output.close();
}