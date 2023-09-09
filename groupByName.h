#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>

#include "groupBy.h"

namespace group {

    class groupByName final : public groupBy {
    public:
        void group(const std::vector<object> &data) override;

        void printInFile(std::ofstream &out) override;

    private:
        std::unordered_map<char, std::vector<const object *>> groups;
    };
}
