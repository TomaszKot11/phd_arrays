//
// Created by kotto on 02.10.2023.
//

#include "PlainInitArray.h"



PlainInitArray::PlainInitArray(int N_, double DEFAULT_VALUE_) : N(N_), DEFAULT_VALUE(DEFAULT_VALUE_) {
        this->data = std::vector<int32_t>(N_, DEFAULT_VALUE_);
//        std::vector<int32_t> data(N_, DEFAULT_VALUE_);
////            t1 = microseconds();
////            t2 = microseconds();
////            temp_times[0] = t1;
//             data = std::move(a);
}

double PlainInitArray::read(int i) {
//        std::cout << data << std::endl;
        std::cout << "read PlainInitArray" << std::endl;
        return data[i];
}

void PlainInitArray::write(int i, double value) {
    std::cout << "write PlainInitArray" << std::endl;
    data[i] = value;
};
