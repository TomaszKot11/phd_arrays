//
// Created by kotto on 04.10.2023.
//

#include "Array.h"
#include <vector>

#ifndef UNTITLED_NAVARROINITARRAY_H
#define UNTITLED_NAVARROINITARRAY_H


class NavarroInitArray: public Array {
    public:
        int N;
        int DEFAULT_VALUE;
        std::vector<int64_t> A;
        std::vector<int> C;
        std::vector<int64_t> B; // bitman from simple
        std::vector<int> S;
        int top;
//        std::array<int64_t, 2> temp_times;

    NavarroInitArray(int N_, int DEFAULT_VALUE_) : N(N_), DEFAULT_VALUE(DEFAULT_VALUE_), top(-1){
        int top = -1;  // top index of the stack
//        int integer_part = this->N / 64 * 64;
        int remainder_part = this->N % 64;
        int no_bits = 0;
        if (remainder_part > 0) { // trenary
            no_bits = N + (64 - remainder_part);
        } else {
            no_bits = N;
        }
//        this->B = std::vector<int64_t>(N_ // 64, 0);
//        global temp_times;

//        int no_bits = N_ + ((64 - (N_ % 64))
//        if N_ % 64 > 0 else 0);
//        int64_t B[no_bits / 64];

//        int32_t C[no_bits / 64];
//        int32_t S[no_bits / 64];  // stack



//        int64_t t1, t2;
//        t1 = chrono::high_resolution_clock::now().time_since_epoch().count();
//        t2 = chrono::high_resolution_clock::now().time_since_epoch().count();
//        temp_times[0] = t1;
//        temp_times[1] = t2;
    }

    double read(int i) {
        int index_in_B = i / 64;
        bool initialized = (0 <= this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);
        if (!initialized) {
            return DEFAULT_VALUE;
        } else {
            bool cur_bit = (this->B[index_in_B] >> (i % 64)) & 1;
            if (cur_bit == 1) {
                return this->A[i];
            } else {
                return DEFAULT_VALUE;
            }
        }
    }

    void write(int i, int value) {
        int index_in_B = i / 64;
        bool initialized = (0 <= this->C[index_in_B] && this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);
        if (initialized) {
//            uint64_t tmp = this->B[index_in_B].astype(uint64_t, casting = "unsafe");
            uint64_t tmp;
            tmp |= 1ULL << (i % 64);
//            this->B[index_in_B] = tmp.astype(int64_t, casting = "unsafe");
        } else {
            this->top += 1;
            this->S[this->top] = index_in_B;
            this->C[index_in_B] = this->top;
            this->B[index_in_B] = 1LL << (i % 64);
        }
        this->A[i] = value;
    }
};


#endif //UNTITLED_NAVARROINITARRAY_H
