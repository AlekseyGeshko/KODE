#include "readData.h"

using namespace std;

readData::readData(const string& input_file): input(input_file) {}

vector<object> readData::getObjects() {
    vector<object> input_objects;
    object curr_object;
    while (input >> curr_object.name >> curr_object.x
                 >> curr_object.y >> curr_object.type >> curr_object.time) {
        input_objects.push_back(move(curr_object));
    }
    return input_objects;
}

readData::~readData() {
    input.close();
}