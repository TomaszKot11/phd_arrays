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
#include <chrono>

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
        return array_ptr->get_B();
    } else if (field_name == "C") {
        return array_ptr->get_C();
    } else if (field_name == "S") {
        return array_ptr->get_S();
    } else if (field_name == "N") {
        return array_ptr->get_N();
    } else if (field_name == "top") {
        return array_ptr->get_top();
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

        std::cout << "Starting benchmarking" << std::endl;
            // SYF
        constexpr int n = 1000000;

        std::map<std::string, int> init_times;
        std::unordered_map<std::string, int> memory_usage;

        for (const std::string& array_type : array_types) {
            std::cout << "LOOP" << std::endl;
            // TODO: memory allocation
            auto cur_array = make_pair(array_type,  create_instance(array_type, n, default_value));
            std::string array_type_name = cur_array.first.substr(array_type.length() - 2);
//            init_times[array_type_name] = temp_times[1] - temp_times[0];

            size_t tmp_size = 0;
            for (const std::string& field_name : {"B", "C", "S", "N", "top"}) {
                std::cout << "LOOP 2" << std::endl;
                // TODO: refactor/catch the error
                tmp_size += get_property_size(cur_array.second, field_name);
            }

//            if (array_type_name == "InterleavedFolkloreInitArray" || array_type_name == "InterleavedFolkloreInitArray2") {
//                tmp_size += asizeof(cur_array.second->A) / 2;
//            } else if (array_type_name == "InterleavedSimpleInitArray64a") {
//                tmp_size += asizeof(cur_array.second->A) / 33;  // only approximately
//            }

            memory_usage[array_type] = tmp_size;
        }

        std::cout << "Memory usage: " << memory_usage.size() << std::endl;
        for(auto it = memory_usage.cbegin(); it != memory_usage.cend(); ++it)
        {
            std::cout << it->first << " " << it->second << "\n";
        }
//        std::cout << memory_usage << std::endl;

        // END SYF
        // Random operation time tests
//        int m = 1000000;
//        std::vector<int> queries1(m);
//        std::vector<int> queries2;
//
//        for (int i = 0; i < m; i++) {
//            // TODO: use C++11 random?
//            queries1[i] = rand() % n;
//        }
//
//        //  queries2 = list(range(m // 2)) + list(range(n - m // 2, n))
//        for (int i = 0; i < m / 2; i++) {
//            queries2.push_back(i);
//        }
//
//        auto t1 = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < m; i++) {
//            std::cout << queries1[i] << " ";
//        }
//        auto t2 = std::chrono::high_resolution_clock::now();
//        auto write_times = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
//
//        std::vector<int> tmp_list;
//
//        t1 = std::chrono::high_resolution_clock::now();
//        for (int i = m - 1; i >= 0; i--) {
//            int item = queries1[i];
//            tmp_list.push_back(item);
//        }
//        t2 = std::chrono::high_resolution_clock::now();
//        auto results = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);

//        t2 = std::chrono::high_resolution_clock::now();
//        auto results = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
//
//        vector<int> queries1_times(m);
//        for (int i = 0; i < m; i++) {
//            int item = tmp_list[i];
//            queries1_times[i] = cur_array.read(item);


            // TODO: perform memory and time tests
            delete createdArray;
    }

    std::cout << "Hello World" << std::endl;

    return 0;
}
