//
// Created by kotto on 03.10.2023.
//

#include "Array.h"
#include <vector>
#include <chrono>

#ifndef UNTITLED_SIMPLEINITARRAY_H
#define UNTITLED_SIMPLEINITARRAY_H


class SimpleInit32Array : public Array {
    private:
        const int N_;
        const int DEFAULT_VALUE_;
        uint32_t* B_; // uint32_t
        int32_t* data; // int32_t to be sure
        size_t B_size;
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> stop_time;
    public:
        SimpleInit32Array(int N_, double DEFAULT_VALUE_);
        ~SimpleInit32Array();

        double read(int i) override;
        void write(int i, double value) override;

        size_t get_N() override;
        size_t get_B() override;
};


#endif //UNTITLED_SIMPLEINITARRAY_H
