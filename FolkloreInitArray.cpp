//
// Created by kotto on 04.10.2023.
//

#include <iostream>
#include "FolkloreInitArray.h"

FolkloreInitArray::FolkloreInitArray(int N_, int DEFAULT_VALUE_) : N_(N_), DEFAULT_VALUE_(DEFAULT_VALUE_), top(-1){
    this->data = std::vector<int32_t>(N_, DEFAULT_VALUE_); // empty_like

    // If this is a stack is it right to initialize it "up-front" with N * int32_t
    this->S = std::vector<int32_t>(N_, DEFAULT_VALUE_); // "stack"
    this->C = std::vector<int32_t>(N_, DEFAULT_VALUE_); // empty_like

    this->top = -1; // V <- -1
}

// i as int32_t ?
double FolkloreInitArray::read(int i) {
    // Complexity -> traverse stack so size(STACK) + n
    return is_initialized(i) ? this->data[i] : this->DEFAULT_VALUE_;
}

// int32_t as i,
void FolkloreInitArray::write(int i, double value) {
    // assign the value
    this->data[i] = value; // value should be int32_t
    if(!is_initialized(i)) {
        this->top++;
        // PUSH TO THE STACK ON TOP POSITION the index i
        this->S[this->top] = i;
        this->C[i] = this->top;
    }
}

//int32_t?
int FolkloreInitArray::is_initialized(int i) {
    // 0 <= C[i] <= top & S[C[i]] = i
    return 0 <= this-> C[i] <= top && S[C[i]] == i;
}
