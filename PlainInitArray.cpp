//
// Created by kotto on 02.10.2023.
//

#include "PlainInitArray.h"



PlainInitArray::PlainInitArray(int N_, double DEFAULT_VALUE_) : N(N_), DEFAULT_VALUE(DEFAULT_VALUE_) {
        this->data = new int32_t[N_];

        this->start_time = std::chrono::steady_clock::now();
        this->stop_time = std::chrono::steady_clock::now();
}

double PlainInitArray::read(int i) {
        std::cout << "PlainInitArray read" << std::endl;
        return data[i];
}

void PlainInitArray::write(int i, double value) {
    std::cout << "PlainInitArray write" << std::endl;
    data[i] = (int32_t)value;
};

PlainInitArray::~PlainInitArray() {
    delete[] this->data;
}
