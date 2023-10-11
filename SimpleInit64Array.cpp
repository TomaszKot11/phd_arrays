//
// Created by kotto on 07.10.2023.
//

#include "SimpleInit64Array.h"

#include <chrono>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>

//TODO: costexpr somewhere else
constexpr int NO_BITS = 64;
constexpr int SET_BIT = 1;

SimpleInit64Array::SimpleInit64Array(size_t N_, int32_t DEFAULT_VALUE_) {
    this->N = N_;
    this->DEFAULT_VALUE = DEFAULT_VALUE_;
    double no_bits = this->N % NO_BITS > 0 ? this->N : this->N + ((NO_BITS - this->N % NO_BITS));

    this->data = new int32_t[N];
    this->DEFAULT_VALUE = DEFAULT_VALUE;
    this->B_size = (size_t)ceil(no_bits / NO_BITS);
    this->B_ = new int64_t[this->B_size];

    // Measure time of array init for cumulative measures
    this->start_time = std::chrono::steady_clock::now();
    memset(B_, 0, B_size * sizeof(uint64_t));
    this->stop_time =  std::chrono::steady_clock::now();
}

int32_t SimpleInit64Array::read(size_t i) {
    uint64_t index = ceil(i / NO_BITS);
    uint64_t value_shifted_64_bits_mod = this->B_[index] >> (i % NO_BITS); // traverse downwards
    uint64_t bit_mask = SET_BIT; // 0000(...)1

    return (value_shifted_64_bits_mod & bit_mask) == SET_BIT ? this->data[i] : this->DEFAULT_VALUE;
}

// TODO: value should be uint32_t
void SimpleInit64Array::write(size_t i, int32_t value) {
    this->data[i] = value; // for now force int64_t; later adjust it?
    B_[i / NO_BITS] |= (SET_BIT << (i % NO_BITS)); // if set the do nothing otherwise set the nth Bit
};

SimpleInit64Array::~SimpleInit64Array() {
    delete[] this->data;
    delete[] this->B_;
}

size_t SimpleInit64Array::get_N() {
    return sizeof(this->N);
}

size_t SimpleInit64Array::get_B() {
    return sizeof(uint64_t) * this->B_size;
}