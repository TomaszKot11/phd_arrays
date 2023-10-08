#include <iostream>
#include <vector>
#include <variant>
#include "Array.h"
#include "PlainInitArray.h"
#include "SimpleInit32Array.h"
#include "SimpleInit64Array.h"
#include "FolkloreInitArray.h"
#include "NavarroInitArray.h"
#include <map>

// Array types to test
const std::vector<std::string > array_types = {
        "PlainInitArray",
        "SimpleInit32Array",
        "SimpleInit64Array",
        "FolkloreInitArray",
        "NavarroInitArray"
//            "SimpleInitArray64a",
//            "InterleavedSimpleInitArray64a",
//            "InterleavedFolkloreInitArray_v1",
//            "InterleavedFolkloreInitArray_v2",
//            "BlockSimpleInitArray8_64",
//            "BlockFolkloreHybridInitArray"
};

// TODO: refactor this
size_t get_property_size(Array* array_ptr, std::string field_name) {
    if (field_name == "B") {
        array_ptr->get_B();
    } else if (field_name == "C") {
        array_ptr->get_C();
    } else if (field_name == "S") {
        array_ptr->get_S();
    } else if (field_name == "N") {
        array_ptr->get_N();
    } else if (field_name == "top") {
        array_ptr->get_top();
    } else {
        throw std::runtime_error("Invalid attribute name");
    }
}

// unique_ptr?
Array* create_instance(std::string alg_name, int n, double default_value) {
    if(alg_name == "PlainInitArray") {
        return new PlainInitArray(n, default_value);
    } else if(alg_name == "SimpleInit32Array") {
        return new SimpleInit32Array(n, default_value);
    } else if(alg_name == "SimpleInit64Array") {
        return new SimpleInit64Array(n, default_value);
    } else if(alg_name == "FolkloreInitArray") {
        return new FolkloreInitArray(n, default_value);
    } else if(alg_name == "NavarroInitArray") {
        return new NavarroInitArray(n, default_value);
    }
}

int main() {
    const int n = (1 << 27) + 5;
    const int32_t default_value = -1;

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

//            for(std::string cur_array : array_types) {
//
//            }

            // SYF
        constexpr int n = 1000000;

        std::map<std::string, int> init_times;
        std::unordered_map<std::string, int> memory_usage;

        for (const std::string& array_type : array_types) {
            // TODO: memory allocation
            auto cur_array = make_pair(array_type,  create_instance(array_type, n, default_value));
            std::string array_type_name = cur_array.first.substr(array_type.length() - 2);
//            init_times[array_type_name] = temp_times[1] - temp_times[0];

            size_t tmp_size = 0;
            for (const std::string& field_name : {"B", "C", "S", "N", "top"}) {
                // TODO: refactor/catch the error
                tmp_size += get_property_size(cur_array.second, field_name);
            }

//            if (array_type_name == "InterleavedFolkloreInitArray" || array_type_name == "InterleavedFolkloreInitArray2") {
//                tmp_size += asizeof(cur_array.second->A) / 2;
//            } else if (array_type_name == "InterleavedSimpleInitArray64a") {
//                tmp_size += asizeof(cur_array.second->A) / 33;  // only approximately
//            }

            memory_usage[array_type_name] = tmp_size;
        }

        // END SYF

            // TODO: perform memory and time tests
            delete createdArray;
    }

    std::cout << "Hello World" << std::endl;

    return 0;
}
