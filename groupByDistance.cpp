#include "groupByDistance.h"

using namespace group;

double groupByDistance::returnDistanceObj(const object &obj) {
    return std::sqrt(obj.x * obj.x + obj.y * obj.y);
}

void groupByDistance::group(const std::vector<object>& data) {
    for (int i = 0; i < data.size(); ++i) {
        double curr_dist = returnDistanceObj(data[i]);
        if (curr_dist <= 100.0) {
            one_hundred.push_back(&data[i]);
        } else if (curr_dist <= 200.0) {
            two_hundred.push_back(&data[i]);
        } else {
            far_away.push_back(&data[i]);
        }
    }
}

void groupByDistance::printInFile(std::ofstream& out) {
    out << "--------Группировка по расстоянию--------\n";
    if (!one_hundred.empty()) {
        out << "100\n";
        printGroup(sortGroup(one_hundred), out);
    }
    if (!two_hundred.empty()) {
        out << "200\n";
        printGroup(sortGroup(two_hundred), out);
    }
    if (!far_away.empty()) {
        out << "Далеко\n";
        printGroup(sortGroup(far_away), out);
    }
}
