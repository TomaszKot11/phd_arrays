#include <iostream>
#include <cstdint>
#include <vector>
#include <variant>

int main() {
    const int n = (1 << 27) + 5;
    const int32_t default_value = -1;

    // Array types to test
    const std::vector<std::string > array_types = {
            "PlainInitArray",
            "SimpleInitArray",
            "SimpleInitArray64",
            "SimpleInitArray64a",
            "FolkloreInitArray",
            "NavarroInitArray",
            "InterleavedSimpleInitArray64a",
            "InterleavedFolkloreInitArray_v1",
            "InterleavedFolkloreInitArray_v2",
            "BlockSimpleInitArray8_64",
            "BlockFolkloreHybridInitArray"
    };

//    std::vector<
//            std::tuple<std::string, std::variant<int, std::pair<int, int>>,
//            std::variant<int, std::pair<int, int>>>
//            >ops

        std::vector<std::tuple<std::string, int, int>> ops = {
                            std::make_tuple("read", 123, 123), std::make_tuple("write", 2, 100), std::make_tuple("write", 123, 789),
                            std::make_tuple("write", 1LL << 27 | 3, 81), std::make_tuple("read", 2, 2), std::make_tuple("read", 3, 3),
                            std::make_tuple("read", 123, 123), std::make_tuple("read", 1LL << 27 | 3, 1LL << 27 | 3)
                           };

    for(std::string alg_type : array_types) {
            std::vector<std::string> ops = {"read", "write"};
            std::string array_type = "my_array";
            int n = 10;
            std::vector<std::string> cur_array(n, "default");
            std::string array_type_name = std::string(array_type).substr(array_type.find_last_of('.') + 1);
            std::cout << left << setw(40) << array_type_name << "\t";
            for (const std::string &op : ops) {
                if (op == "read") {
                    std::cout << cur_array[1] << "\t";
                } else if (op == "write") {
                    cur_array[1] = "new_value";
                } else {
                    throw std::runtime_error("Invalid operation");
                }
            }
            std::cout << std::endl;
    }

    std::cout << "Hello World" << std::endl;

    return 0;
}
