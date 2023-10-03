//
// Created by kotto on 04.10.2023.
//

#include <iostream>
#include "FolkloreInitArray.h"

FolkloreInitArray::FolkloreInitArray(int N_, int DEFAULT_VALUE_) : N_(N_), DEFAULT_VALUE_(DEFAULT_VALUE_), top(-1){
    this->S = std::vector<int>(N_, DEFAULT_VALUE_);
    this->C = std::vector<int>(N_, DEFAULT_VALUE_);
    this->A = std::vector<int>(N_, DEFAULT_VALUE_);
    this->top = -1;
}

double FolkloreInitArray::read(int i) {
    if (C[i] <= top && S[C[i]] == i) {
        return A[i];
    } else {
        return DEFAULT_VALUE_;
    }
}

void FolkloreInitArray::write(int i, double value) {
    if (!((C[i] <= top) && (S[C[i]] == i))) {
        top++;
        S[top] = i;
        C[i] = top;
    }
    A[i] = value;
}
