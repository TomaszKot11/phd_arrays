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
        int32_t DEFAULT_VALUE;
        size_t N;
        int32_t* data;
        uint64_t* B_; // uint32_t
        int32_t* C;
        int32_t* S; // TODO: empty_like
        int top;
        size_t B_size;
    public:
        NavarroInitArray(size_t N_, int32_t DEFAULT_VALUE_);

        int32_t read(size_t i) override;
        void write(size_t i, int32_t value) override;

        size_t get_N() override;
        size_t get_S() override;
        size_t get_C() override;
        size_t get_top() override;
        size_t get_B() override;
};


#endif //UNTITLED_NAVARROINITARRAY_H
