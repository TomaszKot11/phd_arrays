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
#include <random>

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
        throw std::runtime_error("Invalid field name");
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
    } else {
        throw std::runtime_error("Invalid array type");
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
        Array *createdArray = create_instance(cur_array, n, default_value);

        for (auto const &[path, status, size]: opss) {
            if (path == "read") {
                createdArray->read(status);
            } else if (path == "write") {
                createdArray->write(status, size);
            } else {
                throw std::runtime_error("Invalid operation");
            }
            std::cout << std::endl;
        }
    }

        std::cout << "Starting memory benchmarking" << std::endl;
        // SYF
        constexpr int nn = 1000000;

//        std::map<std::string, int> init_times;
        std::unordered_map<std::string, int> memory_usage;
        std::unordered_map<std::string, std::chrono::nanoseconds> write_times;
        std::unordered_map<std::string, std::chrono::nanoseconds> read_times;
        std::unordered_map<std::string, std::chrono::nanoseconds> init_times;

        for (const std::string &array_type: array_types) {
            // TODO: memory allocation
            auto cur_array = make_pair(array_type, create_instance(array_type, nn, default_value));
            std::string array_type_name = cur_array.first.substr(array_type.length() - 2);

            size_t tmp_size = 0;
            for (const std::string &field_name: {"B", "C", "S", "N", "top"}) {
                // TODO: refactor/catch the error
                tmp_size += get_property_size(cur_array.second, field_name);
            }

//            if (array_type_name == "InterleavedFolkloreInitArray" || array_type_name == "InterleavedFolkloreInitArray2") {
//                tmp_size += asizeof(cur_array.second->A) / 2;
//            } else if (array_type_name == "InterleavedSimpleInitArray64a") {
//                tmp_size += asizeof(cur_array.second->A) / 33;  // only approximately
//            }

            memory_usage[array_type] = tmp_size;


            std::cout << "Start read/write benchmarking" << std::endl;

            // TODO: consexpr?
            const int m = 1000000;

            std::vector<int> queries1;
            std::random_device rd;
            std::mt19937 gen(rd());

            std::chrono::time_point<std::chrono::high_resolution_clock> t1, t2;

            // generate queries as int numbers
            for (int i = 0; i < m; i++) {
                queries1.push_back(std::uniform_int_distribution<int>(0, n - 1)(gen));
            }

            Array* createdArray = cur_array.second;

            t1 = std::chrono::high_resolution_clock::now();
            for(int i = 0 ; i < m; i++) {
                createdArray->write(i, queries1[i]);
            }
            t2 = std::chrono::high_resolution_clock::now();

            write_times[array_type] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);

            // reverse queries digits
            std::reverse(queries1.begin(), queries1.end());
            std::vector<int> tmp_list(m);

            t1 = std::chrono::high_resolution_clock::now();
            for(int i = 0; i < m; i++) {
                tmp_list[i] = createdArray->read(i);
            }
            t2 = std::chrono::high_resolution_clock::now();

            read_times[array_type] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);


            // gather init times
            init_times[array_type] = std::chrono::duration_cast<std::chrono::nanoseconds>(createdArray->get_stop_time() - createdArray->get_start_time());
            delete createdArray;
        }

        std::cout << "Init times (ns):" << std::endl;
        for (auto it = init_times.cbegin(); it != init_times.cend(); ++it) {
            std::cout << it->first << " " << it->second.count() << "\n";
        }
        std::cout<<std::endl;


        std::cout << "AUX. MEMORY USAGE (bytes):" << std::endl;
        for (auto it = memory_usage.cbegin(); it != memory_usage.cend(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
        std::cout<<std::endl;

        std::cout << "Write times (ns):" << std::endl;
        for (auto it = write_times.cbegin(); it != write_times.cend(); ++it) {
            std::cout << it->first << " " << it->second.count() << std::endl;
        }
        std::cout<<std::endl;

        std::cout << "Read times (ns):" << std::endl;
        for (auto it = read_times.cbegin(); it != read_times.cend(); ++it) {
            std::cout << it->first << " " << it->second.count() << std::endl;
        }
        std::cout<<std::endl;

    return 0;
}
