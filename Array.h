//
// Created by kotto on 02.10.2023.
//

#include <cstdint>
#include <chrono>

#ifndef UNTITLED_ARRAY_H
#define UNTITLED_ARRAY_H


class Array {
    protected:
        size_t N;
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> stop_time;
    public:
        const size_t GET_N() {
            return N;
        }

//        const T GET_DEFAULT_VALUE() {
//            return DEFAULT_VALUE;
//        }

        virtual int read(size_t i) = 0;
        virtual void write(size_t i, int value) = 0;

        // boilerplate - no reflection "B", "C", "S", "N", "top"
        virtual size_t get_B() {
            return 0;
        }
        virtual size_t get_C() {
             return 0;
        }
        virtual size_t get_S() {
            return 0;
        }
        virtual size_t get_N() {
            return 0;
        }
        virtual size_t get_top() {
            return 0;
        }

        std::chrono::time_point<std::chrono::steady_clock> get_start_time() {
            return this->start_time;
        }

        std::chrono::time_point<std::chrono::steady_clock> get_stop_time() {
            return this->stop_time;
        }
};


#endif //UNTITLED_ARRAY_H
