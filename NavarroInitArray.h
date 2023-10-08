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

    size_t get_N() override;
    size_t get_S() override;
    size_t get_C() override;
    size_t get_top() override;
    size_t get_B() override;
};


#endif //UNTITLED_NAVARROINITARRAY_H
