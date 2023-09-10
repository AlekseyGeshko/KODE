#include "groupByName.h"

using namespace group;

void groupByName::sortGroups(){
    for (auto &[_, objects]: groups) {
        std::sort(objects.begin(), objects.end(),[](const object* lhs, const object* rhs){
            return lhs->name < rhs->name;
        });
    }
}

void groupByName::group(const std::vector<object>& data) {
    const std::string ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
                                "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (const auto &_object_: data) {
        if (std::find(ru_alph.begin(), ru_alph.end(), _object_.name[0]) != ru_alph.end()) {
            groups[std::string{_object_.name[0]}].push_back(&_object_);
        } else {
            groups["#"].push_back(&_object_);
        }
    }
    sortGroups();
}

void groupByName::printInFile(std::ofstream& out) const {
    out << "--------Группировка по имени--------\n";
    for (auto &[first_symb, objects]: groups) {
        out << first_symb << '\n';
        printGroup(objects, out);
    }
}
