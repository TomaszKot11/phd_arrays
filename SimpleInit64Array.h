//
// Created by kotto on 07.10.2023.
//
#include <chrono>
#include "Array.h"
#include <cstdint>

#ifndef UNTITLED_SIMPLEINIT64ARRAY_H
#define UNTITLED_SIMPLEINIT64ARRAY_H


class SimpleInit64Array : public Array {
private:
    const int N_;
    const int DEFAULT_VALUE_;
    uint64_t* B_; // uint32_t
    int64_t* data; // int32_t to be sure
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    std::chrono::time_point<std::chrono::steady_clock> stop_time;
public:
    SimpleInit64Array(int N_, double DEFAULT_VALUE_);
    ~SimpleInit64Array();

    double read(int i) override;
    void write(int i, double value) override;

    size_t get_N() override;
    size_t get_B() override;
};


#endif //UNTITLED_SIMPLEINIT64ARRAY_H
