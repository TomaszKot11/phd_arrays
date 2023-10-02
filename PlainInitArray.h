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

class PlainInitArray: Array {
    public:
        PlainInitArray(int N_, double DEFAULT_VALUE_) : N(N_), DEFAULT_VALUE(DEFAULT_VALUE_) {
            std::vector<int32_t> a(N_, DEFAULT_VALUE_);
//            t1 = microseconds();
//            t2 = microseconds();
//            temp_times[0] = t1;
//            temp_times[1] = t2;
            data = std::move(a);
        }

        double read(int i) const {
            return data[i];
        }

        void write(int i, double value) {
            data[i] = value;
        }

    private:
        int N;
        double DEFAULT_VALUE;
        std::vector<int32_t> data;
//        microsecond_duration<double, std::nano> t1, t2;
        double temp_times[2];
};


#endif //UNTITLED_PLAININITARRAY_H
