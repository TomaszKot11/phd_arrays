//
// Created by kotto on 03.10.2023.
//

#include "SimpleInitArray.h"
#include <iostream>
#include <vector>
#include <cmath>


SimpleInitArray::SimpleInitArray(int N, double DEFAULT_VALUE) : N_(N), DEFAULT_VALUE_(DEFAULT_VALUE), B_(N / 32 + 1, 0) {
    this->data = std::vector<int32_t>(N_, DEFAULT_VALUE_);
    // understood this but not now -> this should be uint32_t
    int no_bits = this->N_ % 32 > 0 ? this->N_ : this->N_ + ((32 - this->N_ % 32));
    this->B_ = std::vector<uint32_t>(ceil(no_bits / 32));
////            t1 = microseconds(); // why we need the time of filling the bit array (?)
////            t2 = microseconds();
////            temp_times[0] = t1;
//             data = std::move(a);
}

// TODO: int i should be uint32_t ?
double SimpleInitArray::read(int i) {
    uint32_t value_shifted_32_bits_mod = this->B_[ceil(i / 32)] >> (i % 32); // traverse downwards
    uint32_t bit_mask = 1; // 0000(...)1

    return (value_shifted_32_bits_mod & bit_mask) == 1 ? this->data[i] : DEFAULT_VALUE_;
}

// value should be uint32_t
void SimpleInitArray::write(int i, double value) {
    this->data[i] = value;
    B_[i / 32] |= (1 << (i % 32)); // if set the do nothing otherwise set the nth Bit
};
