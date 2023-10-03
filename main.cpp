#include <iostream>
#include <cstdint>
#include <vector>
#include <variant>
#include "Array.h"
#include "PlainInitArray.h"
#include "SimpleInitArray.h"
#include "FolkloreInitArray.h"
#include <map>
#include <chrono>
#include <memory>
#include <cstring>


// unique_ptr?
Array* create_instance(std::string alg_name, int n, double default_value) {
    if(alg_name == "PlainInitArray") {
        return new PlainInitArray(n, default_value);
    } else if(alg_name == "SimpleInitArray") {
        return new SimpleInitArray(n, default_value);
    } else if(alg_name == "FolkloreInitArray") {
        return new FolkloreInitArray(n, default_value);
    }
}

int main() {
    const int n = (1 << 27) + 5;
    const int32_t default_value = -1;

    // Array types to test
    const std::vector<std::string > array_types = {
            "PlainInitArray",
            "SimpleInitArray",
//            "SimpleInitArray64",
//            "SimpleInitArray64a",
            "FolkloreInitArray",
//            "NavarroInitArray",
//            "InterleavedSimpleInitArray64a",
//            "InterleavedFolkloreInitArray_v1",
//            "InterleavedFolkloreInitArray_v2",
//            "BlockSimpleInitArray8_64",
//            "BlockFolkloreHybridInitArray"
    };
        std::vector<std::tuple<std::string, int, int>> opss = {
                            std::make_tuple("read", 123, 123), std::make_tuple("write", 2, 100), std::make_tuple("write", 123, 789),
                            std::make_tuple("write", 1LL << 27 | 3, 81), std::make_tuple("read", 2, 2), std::make_tuple("read", 3, 3),
                            std::make_tuple("read", 123, 123), std::make_tuple("read", 1LL << 27 | 3, 1LL << 27 | 3)
                           };

    for(std::string cur_array : array_types) {
            std::vector<std::string> ops = {"read", "write"};
            // TODO: memory allocation (?)
            Array* createdArray = create_instance(cur_array, n, default_value);
            std::cout << "Witam serdecznie 1" << std::endl;

            for(auto const& [path, status, size] : opss) {
               if(path == "read") {
                   std::cout << "read" << std::endl;
                   createdArray->read(status);
               } else if(path == "write") {
                   std::cout << "write" << " " << status << " " << size << std::endl;
                   createdArray->write(status, size);
               } else {
                   throw std::runtime_error("Invalid operation");
               }
               std::cout << std::endl;
            }

            // TODO: perform memory and time tests

            delete createdArray;
    }

    std::cout << "Hello World" << std::endl;

    return 0;
}
