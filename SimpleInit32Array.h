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
        int32_t DEFAULT_VALUE;
        int32_t* data;
        uint32_t* B_; // uint32_t
        size_t B_size;
    public:
        SimpleInit32Array(size_t N_, int32_t DEFAULT_VALUE_);
        ~SimpleInit32Array();

        int32_t read(size_t i) override;
        void write(size_t i, int32_t value) override;

        size_t get_N() override;
        size_t get_B() override;
};


#endif //UNTITLED_SIMPLEINITARRAY_H
