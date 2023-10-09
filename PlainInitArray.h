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
        int N;
        double DEFAULT_VALUE;
        int32_t* data; // int32
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> stop_time;
    public:
        PlainInitArray(int N_, double DEFAULT_VALUE_);
        ~PlainInitArray();

        double read(int i);
        void write(int i, double value);

        size_t get_N() override;
};


#endif //UNTITLED_PLAININITARRAY_H
