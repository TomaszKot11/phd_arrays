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
            const int N_;
            const int DEFAULT_VALUE_; // TODO: int32_t
            int32_t top;

            uint32_t* S; // stack
            int32_t* C; // check array
            int32_t* data; // data
            std::chrono::time_point<std::chrono::steady_clock> start_time;
            std::chrono::time_point<std::chrono::steady_clock> stop_time;
        public:
            FolkloreInitArray(int N, int DEFAULT_VALUE);
            ~FolkloreInitArray();

            double read(int i) override;
            void write(int i, double value) override;
            int is_initialized(int i);

            size_t get_N() override;
            size_t get_S() override;
            size_t get_C() override;
            size_t get_top() override;
};


#endif //UNTITLED_FOLKLOREINITARRAY_H
