#include "groupByDistance.h"

using namespace group;

double groupByDistance::returnDistanceObj(const object &obj) const{
    return std::sqrt(obj.x * obj.x + obj.y * obj.y);
}

void groupByDistance::sortGroups() {
    auto comp = [&](const object* lhs, const object* rhs){
        return returnDistanceObj(*lhs) < returnDistanceObj(*rhs);
    };
    std::sort(one_hundred.begin(), one_hundred.end(), comp);
    std::sort(two_hundred.begin(), two_hundred.end(), comp);
    std::sort(far_away.begin(), far_away.end(), comp);
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
    sortGroups();
}

void groupByDistance::printInFile(std::ofstream& out) const{
    out << "--------Группировка по расстоянию--------\n";
    if (!one_hundred.empty()) {
        out << "100\n";
        printGroup(one_hundred, out);
    }
    if (!two_hundred.empty()) {
        out << "200\n";
        printGroup(two_hundred, out);
    }
    if (!far_away.empty()) {
        out << "Далеко\n";
        printGroup(far_away, out);
    }
}
