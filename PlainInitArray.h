//
// Created by kotto on 02.10.2023.
//


#ifndef UNTITLED_PLAININITARRAY_H
#define UNTITLED_PLAININITARRAY_H


#include "Array.h"
#include <array>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cmath>
#include <chrono>

class PlainInitArray: public Array {
    private:
        int32_t DEFAULT_VALUE;
        size_t N;
        int32_t* data; // int32
    public:
        PlainInitArray(size_t N_, int32_t DEFAULT_VALUE_);
        ~PlainInitArray();

        int32_t read(size_t i) override;
        void write(size_t i, int32_t value) override;

        size_t get_N() override;
};


#endif //UNTITLED_PLAININITARRAY_H
