//
// Created by kotto on 04.10.2023.
//

#include "NavarroInitArray.h"
#include <cmath>

constexpr int NO_BITS = 64;

NavarroInitArray::NavarroInitArray(int N_, int DEFAULT_VALUE_) : N_(N_), DEFAULT_VALUE_(DEFAULT_VALUE_), top(-1){
    this->data = new int32_t[N_];

    double no_bits = this->N_ % NO_BITS > 0 ? this->N_ : this->N_ + ((NO_BITS - this->N_ % NO_BITS));
    this->B_size = (size_t)ceil(no_bits / NO_BITS);

    this->B_ = new uint64_t[B_size];

    this->C = new int32_t[B_size];
    // If this is a stack is it right to initialize it "up-front" with N * int32_t
    this->S = new int32_t[B_size];

    this->top = -1; // V <- -1 -> explicit

    this->start_time = std::chrono::steady_clock::now();
    this->stop_time = std::chrono::steady_clock::now();
}

double NavarroInitArray::read(int i) {
    int index_in_B = ceil(i / NO_BITS);

    bool initialized = (0 <= this->C[index_in_B] && this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);
    if (!initialized) {
        return this->DEFAULT_VALUE_;
    }
    else {
        bool cur_bit = (this->B_[index_in_B] >> (i % NO_BITS)) & 1;
        if (cur_bit == 1) {
            return this->data[i];
        } else {
            return this->DEFAULT_VALUE_;
        }
    }
}

void NavarroInitArray::write(int i, double value) {
    int index_in_B = ceil(i / NO_BITS);
    bool initialized = (0 <= this->C[index_in_B] && this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);

    if (initialized) {
        uint64_t tmp = (uint64_t)this->B_[index_in_B];
        tmp |= 1 << (i % 64);
        this->B_[index_in_B] = (int64_t)tmp;
    } else {
        this->top += 1;
        this->S[this->top] = index_in_B;
        this->C[index_in_B] = this->top;
        this->B_[index_in_B] = 1 << (i % NO_BITS);
        this->data[i] = value;
    }
}


size_t NavarroInitArray::get_N() {
    return sizeof(this->N_);
}

size_t NavarroInitArray::get_S() {
    return sizeof(int32_t) * this->B_size;
}

size_t NavarroInitArray::get_C() {
    return sizeof(int32_t) * this->B_size;
}

size_t NavarroInitArray::get_top() {
    return sizeof(this->top);
}

size_t NavarroInitArray::get_B() {
    return sizeof(uint64_t) * this->B_size;
}