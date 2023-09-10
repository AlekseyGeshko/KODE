#include "groupByTime.h"

using namespace group;


void groupByTime::sortGroups() {
    auto comp = [](const object* lhs, const object* rhs){
        return lhs->time < rhs->time;
    };
    std::sort(today.begin(), today.end(), comp);
    std::sort(yesterday.begin(), yesterday.end(), comp);
    std::sort(week.begin(), week.end(), comp);
    std::sort(earlier.begin(), earlier.end(), comp);
}

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
    sortGroups();
}

void groupByTime::printInFile(std::ofstream& out) const{
    out << "--------Группировка по времени--------\n";
    if (!today.empty()) {
        out << "За сегодня\n";
        printGroup(today, out);
    }
    if (!yesterday.empty()) {
        out << "За вчера\n";
        printGroup(yesterday, out);
    }
    if (!week.empty()) {
        out << "За неделю\n";
        printGroup(week, out);
    }
    if (!earlier.empty()) {
        out << "Ранее\n";
        printGroup(earlier, out);
    }
}
