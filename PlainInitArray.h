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

class PlainInitArray: public Array {
    private:
        int N;
        double DEFAULT_VALUE;
        std::vector<int32_t> data; // int32
    //        microsecond_duration<double, std::nano> t1, t2;
//        double temp_times[2]{};
    public:
        PlainInitArray(int N_, double DEFAULT_VALUE_);

        double read(int i);
        void write(int i, double value);
};


#endif //UNTITLED_PLAININITARRAY_H
