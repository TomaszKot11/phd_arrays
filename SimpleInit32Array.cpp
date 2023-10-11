//
// Created by kotto on 03.10.2023.
//

#include "SimpleInit32Array.h"
#include <chrono>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstring>

//TODO: costexpr somewhere else
constexpr int NO_BITS = 32;

SimpleInit32Array::SimpleInit32Array(size_t N_, int32_t DEFAULT_VALUE_) {
    this->N = N_;
    this->DEFAULT_VALUE = DEFAULT_VALUE_;
    double no_bits = this->N % NO_BITS > 0 ? this->N : this->N + ((NO_BITS - this->N % NO_BITS));

    this->data = new int32_t[N];
    this->B_size = (size_t)ceil(no_bits / NO_BITS);
    this->B_ = new uint32_t[this->B_size];

    // Measure time of array init for cumulative measures
    this->start_time = std::chrono::steady_clock::now();
    memset(B_, 0, B_size * sizeof(uint32_t));
    this->stop_time =  std::chrono::steady_clock::now();
}

int32_t SimpleInit32Array::read(size_t i) {
    uint32_t index = ceil(i / NO_BITS);
    uint32_t value_shifted_32_bits_mod = this->B_[index] >> (i % NO_BITS); // traverse downwards
    uint32_t bit_mask = (uint32_t)1; // 0000(...)1

    return (value_shifted_32_bits_mod & bit_mask) == 1 ? this->data[i] : this->DEFAULT_VALUE;
}

// TODO: value should be uint32_t
void SimpleInit32Array::write(size_t i, int32_t value) {
    this->data[i] = value; // for now force int32_t; later adjust it?
    B_[i / NO_BITS] |= (1 << (i % NO_BITS)); // if set the do nothing otherwise set the nth Bit
};

SimpleInit32Array::~SimpleInit32Array() {
    delete[] this->data;
    delete[] this->B_;
}

size_t SimpleInit32Array::get_N() {
    return sizeof(this->N);
}

size_t SimpleInit32Array::get_B() {
    return sizeof(uint32_t) * this->B_size;
}