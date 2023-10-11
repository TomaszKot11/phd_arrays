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
        int32_t DEFAULT_VALUE;
        int32_t* data;
        int64_t* B_; // uint32_t
        size_t B_size;
    public:
        SimpleInit64Array(size_t N_, int32_t DEFAULT_VALUE_);
        ~SimpleInit64Array();

        int32_t read(size_t i) override;
        void write(size_t i, int32_t value) override;

        size_t get_N() override;
        size_t get_B() override;
};


#endif //UNTITLED_SIMPLEINIT64ARRAY_H
