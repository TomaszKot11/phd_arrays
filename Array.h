//
// Created by kotto on 02.10.2023.
//

#include <cstdint>
#ifndef UNTITLED_ARRAY_H
#define UNTITLED_ARRAY_H


// TODO: abstract (?)
class Array {
    private:
        int32_t N;
        int32_t DEFAULT_VALUE;
    public:
        const int32_t& GET_N() {
            return N;
        }

        const int32_t& GET_DEFAULT_VALUE() {
            return DEFAULT_VALUE;
        }

        virtual double read(int i) = 0;
        virtual void write(int i, double value) = 0;

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
};


#endif //UNTITLED_ARRAY_H
