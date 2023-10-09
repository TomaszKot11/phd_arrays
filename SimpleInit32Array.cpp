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

SimpleInit32Array::SimpleInit32Array(int N, double DEFAULT_VALUE) : N_(N), DEFAULT_VALUE_(DEFAULT_VALUE) {
    double no_bits = this->N_ % NO_BITS > 0 ? this->N_ : this->N_ + ((NO_BITS - this->N_ % NO_BITS));

    this->data = new int32_t[N_];
    this->B_size = (size_t)ceil(no_bits / NO_BITS);
    this->B_ = new uint32_t[this->B_size];

    // Measure time of array init for cumulative measures
    this->start_time = std::chrono::steady_clock::now();
    memset(B_, 0, B_size * sizeof(uint32_t));
    this->stop_time =  std::chrono::steady_clock::now();
}

double SimpleInit32Array::read(int i) {
    uint32_t index = ceil(i / NO_BITS);
    uint32_t value_shifted_32_bits_mod = this->B_[index] >> (i % NO_BITS); // traverse downwards
    uint32_t bit_mask = (uint32_t)1; // 0000(...)1

    return (value_shifted_32_bits_mod & bit_mask) == 1 ? this->data[i] : DEFAULT_VALUE_;
}

// TODO: value should be uint32_t
void SimpleInit32Array::write(int i, double value) {
    this->data[i] = (int32_t)value; // for now force int32_t; later adjust it?
    B_[i / NO_BITS] |= (1 << (i % NO_BITS)); // if set the do nothing otherwise set the nth Bit
};

SimpleInit32Array::~SimpleInit32Array() {
    delete[] this->data;
    delete[] this->B_;
}

size_t SimpleInit32Array::get_N() {
    std::cout << "SimpleInit32Array N " << sizeof(this->N_) << std::endl;
    return sizeof(this->N_);
}

size_t SimpleInit32Array::get_B() {
    std::cout << "SimpleInit32Array B " << sizeof(uint32_t) * this->B_size << std::endl;
    return sizeof(uint32_t) * this->B_size;
}