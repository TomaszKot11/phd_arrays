//
// Created by kotto on 04.10.2023.
//

#include <vector>
#include "Array.h"
#include <chrono>

#ifndef UNTITLED_FOLKLOREINITARRAY_H
#define UNTITLED_FOLKLOREINITARRAY_H


class FolkloreInitArray: public Array {
        private:
            int32_t top;
            size_t N;
            int32_t DEFAULT_VALUE;
            uint32_t* S; // stack
            int32_t* data;
            int32_t* C; // check array
        public:
            FolkloreInitArray(size_t N, int32_t DEFAULT_VALUE);
            ~FolkloreInitArray();

            int32_t read(size_t i) override;
            void write(size_t i, int32_t value) override;
            int is_initialized(int i);

            size_t get_N() override;
            size_t get_S() override;
            size_t get_C() override;
            size_t get_top() override;
};


#endif //UNTITLED_FOLKLOREINITARRAY_H
