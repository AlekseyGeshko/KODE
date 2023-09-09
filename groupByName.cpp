#include "groupByName.h"

using namespace group;

void groupByName::group(const std::vector<object>& data) {
    const std::string ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
                                "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (const auto &_object_: data) {
        if (std::find(ru_alph.begin(), ru_alph.end(), _object_.name[0]) != ru_alph.end()) {
            groups[std::string{_object_.name[0]}].push_back(&_object_);
        } else {
            groups['#'].push_back(&_object_);
        }
    }
}

void groupByName::printInFile(std::ofstream& out) {
    out << "--------Группировка по имени--------\n";
    for (auto &[first_symb, objects]: groups) {
        out << first_symb << '\n';
        printGroup(sortGroup(objects), out);
    }
}
