#include <peepee.hpp>

#include <iostream>

int main()
{
    pp::initialize();

    auto r = pp::request({
        .url = "https://httpbin.org/get",
        .params = {
            {"key1", "value1"},
            {"key2", "value2"},
        },
    });

    std::cout << r.code << "\n" << r.data << "\n";

    pp::cleanup();
}
