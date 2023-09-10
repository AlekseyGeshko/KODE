#pragma once
#include <memory>
#include <vector>
#include <ctime>

#include "groupBy.h"

namespace group {

    class groupByTime final : public groupBy {
    private:
        const int seconds_in_day = 24 * 60 * 60;
        const int seconds_in_2day = 2 * seconds_in_day;
        const int seconds_in_week = 7 * seconds_in_day;

        void sortGroups();
    public:
        void group(const std::vector<object> &data) override;

        void printInFile(std::ofstream &out) const override;

    private:
        std::vector<const object *> today;
        std::vector<const object *> yesterday;
        std::vector<const object *> week;
        std::vector<const object *> earlier;
    };
}
