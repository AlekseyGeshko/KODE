#include <iostream>

#include "readData.h"
#include "writeData.h"

using namespace std;

void startProgram(){
    int count_elements;
    string input_file, output_file;
    cout << "Введите, пожалуйста, имя входного файла: ";
    cin >> input_file;
    cout << "Введите, пожалуйста, имя выходного файла: ";
    cin >> output_file;
    cout << "Введите, пожалуйста, ограничение по типу: ";
    cin >> count_elements;
    readData readData(input_file);
    writeData writeData(output_file);
    writeData.writeIntoFile(readData.getObjects(), count_elements);
}

int main(){
    startProgram();
    return 0;
}
