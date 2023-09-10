#pragma once
#include <algorithm>
#include "readData.h"

namespace group {

    class groupBy {
    public:
        virtual void group(const std::vector<object> &data) = 0;

        virtual void printInFile(std::ofstream &out) const = 0;
    };

    inline void printGroup(const std::vector<const object *> &elements, std::ofstream &out) {
        for (const object *elem: elements) {
            out << *elem;
        }
        out << std::endl;
    }
}
