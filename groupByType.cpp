#include "groupByType.h"
#include <vector>

#include "readData.h"

using namespace group;

void groupByType::createGroups(const std::vector<object>& data){
    for (size_t i = 0; i < data.size(); ++i) {
        ++my_groups[data[i].type].first;
        my_groups[data[i].type].second.push_back(&data[i]);
    }
}

void groupByType::addElements(std::vector<const object*>& elements, std::vector<const object*> objects) {
    for (size_t i = 0; i < objects.size(); ++i) {
        elements.push_back(objects[i]);
    }
}

groupByType::groupByType(int _need_objects): need_objects(_need_objects){}

void groupByType::group(const std::vector<object>& data){
    createGroups(data);
}

void groupByType::printInFile(std::ofstream& out) {
    std::vector<const object *> difference_elements;
    out << "--------Группировка по типу--------\n";
    for (const auto &[type, count_index]: my_groups) {
        if (count_index.first <= need_objects) {
            addElements(difference_elements, count_index.second);
        } else {
            std::vector<const object *> elements;
            addElements(elements, count_index.second);
            out << elements[0]->type << '\n';
            printGroup(sortGroup(elements), out);
        }
    }
    if (!difference_elements.empty()) {
        out << "Разное\n";
        printGroup(sortGroup(difference_elements), out);
    }
}