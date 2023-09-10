#include "groupByType.h"
#include <vector>

#include "readData.h"

using namespace group;

void groupByType::sortGroup(std::vector<const object *>& elements){
    std::sort( elements.begin(),   elements.end(),
              [](const object* lhs, const object* rhs){
                  return lhs->name < rhs->name;
              });
}

void groupByType::createGroups(const std::vector<object>& data){
    for (size_t i = 0; i < data.size(); ++i) {
        ++my_groups[data[i].type].first;
        my_groups[data[i].type].second.push_back(&data[i]);
    }
    for (auto &[_, count_index]: my_groups) {
        if (count_index.first <= need_objects) {
            addElements(count_index.second);
        }else{
            sortGroup(count_index.second);
        }
    }
    sortGroup(difference_elements);
}

void groupByType::addElements(std::vector<const object*>& objects) {
    for (size_t i = 0; i < objects.size(); ++i) {
        difference_elements.push_back(objects[i]);
    }
}

groupByType::groupByType(int _need_objects): need_objects(_need_objects){}

void groupByType::group(const std::vector<object>& data){
    createGroups(data);
}

void groupByType::printInFile(std::ofstream& out) const{
    out << "--------Группировка по типу--------\n";
    for (const auto &[type, count_index]: my_groups) {
        if (count_index.first > need_objects && !count_index.second.empty()) {
            out << count_index.second[0]->type << '\n';
            printGroup(count_index.second, out);
        }
    }
    if (!difference_elements.empty()) {
        out << "Разное\n";
        printGroup(difference_elements, out);
    }
}
