#include "groupByTime.h"

using namespace group;

void groupByTime::group(const std::vector<object>& data) {
    for (const auto &obj: data) {
        auto curr_time = time(nullptr);
        if (abs(curr_time - obj.time) <= seconds_in_day) {
            today.push_back(&obj);
        } else if (abs(curr_time - obj.time) <= seconds_in_2day) {
            yesterday.push_back(&obj);
        } else if (abs(curr_time - obj.time) <= seconds_in_week) {
            week.push_back(&obj);
        } else {
            earlier.push_back(&obj);
        }
    }
}

void groupByTime::printInFile(std::ofstream& out) {
    out << "--------Группировка по времени--------\n";
    if (!today.empty()) {
        out << "За сегодня\n";
        printGroup(sortGroup(today), out);
    }
    if (!yesterday.empty()) {
        out << "За вчера\n";
        printGroup(sortGroup(yesterday), out);
    }
    if (!week.empty()) {
        out << "За неделю\n";
        printGroup(sortGroup(week), out);
    }
    if (!earlier.empty()) {
        out << "Ранее\n";
        printGroup(sortGroup(earlier), out);
    }
}