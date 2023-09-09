#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "groupBy.h"
#include "readData.h"

namespace group {

    class groupByType final : public groupBy {
    private:
        using type_groups = std::unordered_map<std::string_view,
                std::pair<int, std::vector<const object *>>>;

        void createGroups(const std::vector<object> &data);

        void addElements(std::vector<const object *> &elements, std::vector<const object *> objects);

    public:
        groupByType(int _need_objects);

        void group(const std::vector<object> &data) override;

        void printInFile(std::ofstream &out) override;

    private:
        type_groups my_groups;
        int need_objects;
    };
}
