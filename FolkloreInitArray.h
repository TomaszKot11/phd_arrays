//
// Created by kotto on 04.10.2023.
//

#include <vector>
#include "Array.h"

#ifndef UNTITLED_FOLKLOREINITARRAY_H
#define UNTITLED_FOLKLOREINITARRAY_H


class FolkloreInitArray: public Array {
        private:
            const int N_;
            const int DEFAULT_VALUE_;
            int top;
            std::vector<int32_t> S,C, data; // "stack", check array, data
public:
    FolkloreInitArray(int N, int DEFAULT_VALUE);

    double read(int i) override;
    void write(int i, double value) override;
    int is_initialized(int i) ;
};


#endif //UNTITLED_FOLKLOREINITARRAY_H
