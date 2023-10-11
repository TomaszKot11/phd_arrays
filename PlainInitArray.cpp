//
// Created by kotto on 02.10.2023.
//

#include <cstring>
#include "PlainInitArray.h"



PlainInitArray::PlainInitArray(size_t N_, int32_t DEFAULT_VALUE_) {
        this->N = N_;
        this->DEFAULT_VALUE = DEFAULT_VALUE_;
        this->data = new int32_t[N_];

        this->start_time = std::chrono::steady_clock::now();
        memset(this->data, DEFAULT_VALUE_, N * sizeof(uint32_t));
        this->stop_time = std::chrono::steady_clock::now();
}

int32_t PlainInitArray::read(size_t i) {
        return data[i];
}

void PlainInitArray::write(size_t i, int32_t value) {
    data[i] = value;
};

PlainInitArray::~PlainInitArray() {
    delete[] this->data;
}

size_t PlainInitArray::get_N() {
    return sizeof(this->N);
}
