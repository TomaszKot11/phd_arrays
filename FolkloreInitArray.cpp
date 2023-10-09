//
// Created by kotto on 04.10.2023.
//

#include <iostream>
#include "FolkloreInitArray.h"
#include <chrono>

FolkloreInitArray::FolkloreInitArray(int N_, int DEFAULT_VALUE_) : N_(N_), DEFAULT_VALUE_(DEFAULT_VALUE_), top(-1){
    this->data = new int32_t[N_];// empty_like

    // If this is a stack is it right to initialize it "up-front" with N * int32_t
    this->S = new uint32_t[N_];// "stack"
    this->C = new int32_t[N_];// empty_like

    this->top = -1; // V <- -1

    this->start_time = std::chrono::steady_clock::now();
    this->stop_time = std::chrono::steady_clock::now();
}

// i as int32_t ?, return int32_t
double FolkloreInitArray::read(int i) {
    // Complexity -> traverse stack so size(STACK) + n
    return is_initialized(i) ? this->data[i] : this->DEFAULT_VALUE_;
}

// uint32_t as i, double as int32_t (?)
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

// TODO: i as uint32_t
int FolkloreInitArray::is_initialized(int i) {
    return 0 <= this->C[i] <= top && S[C[i]] == (uint32_t)i;
}

FolkloreInitArray::~FolkloreInitArray() {
    // TODO: free the memory
    delete[] this->data;
    delete[] this->S;
    delete[] this->C;
}

// boilerplate
size_t FolkloreInitArray::get_N() {
    return sizeof(this->N_);
}

// TODO: this is size of a pointer
size_t FolkloreInitArray::get_S() {
    return sizeof(uint32_t) * this->N_;
}

size_t FolkloreInitArray::get_C() {
    return sizeof(int32_t) * this->N_;
}

size_t FolkloreInitArray::get_top() {
    return sizeof(this->top);
}
