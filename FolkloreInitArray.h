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
            std::vector<int> S, C;
            std::vector<int> A;
public:
    FolkloreInitArray(int N, int DEFAULT_VALUE);

    double read(int i);
    void write(int i, double value);
};


#endif //UNTITLED_FOLKLOREINITARRAY_H
