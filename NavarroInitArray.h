//
// Created by kotto on 04.10.2023.
//

#include "Array.h"
#include <vector>
#include <chrono>

#ifndef UNTITLED_NAVARROINITARRAY_H
#define UNTITLED_NAVARROINITARRAY_H


class NavarroInitArray: public Array {
    private:
        const int N_;
        const int DEFAULT_VALUE_;
        uint64_t* B_; // uint32_t
        int32_t* C;
        int32_t* S; // TODO: empty_like
        int top;
        int32_t* data;
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> stop_time;
    public:
    NavarroInitArray(int N_, int DEFAULT_VALUE_);

    double read(int i) override;
    void write(int i, double value) override;

    //{
//        int index_in_B = i / 64;
//        bool initialized = (0 <= this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);
//        if (!initialized) {
//            return DEFAULT_VALUE;
//        } else {
//            bool cur_bit = (this->B[index_in_B] >> (i % 64)) & 1;
//            if (cur_bit == 1) {
//                return this->A[i];
//            } else {
//                return DEFAULT_VALUE;
//            }
//        }
//    }

   // {
//        int index_in_B = i / 64;
//        bool initialized = (0 <= this->C[index_in_B] && this->C[index_in_B] <= this->top) && (this->S[this->C[index_in_B]] == index_in_B);
//        if (initialized) {
//            uint64_t tmp = this->B[index_in_B].astype(uint64_t, casting = "unsafe");
//            uint64_t tmp;
//            tmp |= 1ULL << (i % 64);
//            this->B[index_in_B] = tmp.astype(int64_t, casting = "unsafe");
//        } else {
//            this->top += 1;
//            this->S[this->top] = index_in_B;
//            this->C[index_in_B] = this->top;
//            this->B[index_in_B] = 1LL << (i % 64);
//        }
//        this->A[i] = value;
//    }
};


#endif //UNTITLED_NAVARROINITARRAY_H
