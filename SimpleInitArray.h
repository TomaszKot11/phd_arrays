//
// Created by kotto on 03.10.2023.
//

#include "Array.h"
#include <vector>

#ifndef UNTITLED_SIMPLEINITARRAY_H
#define UNTITLED_SIMPLEINITARRAY_H


class SimpleInitArray: public Array {
    private:
        const int N_;
        const int DEFAULT_VALUE_;
        std::vector<uint32_t> B_; // uint32_t
        std::vector<int32_t> data; // int32_t to be sure
//        vector<uint32_t> B_;
//        vector<int> A_;
//        vector<uint64_t> temp_times_;
    public:
        SimpleInitArray(int N_, double DEFAULT_VALUE_);

        double read(int i);
        void write(int i, double value);
};


#endif //UNTITLED_SIMPLEINITARRAY_H
