#include <peepee.hpp>

#include <iostream>

int main()
{
    pp::initialize();

    auto response = pp::request({
        .url = "http://google.com",
    });

    std::cout << response.code << "\n" << response.data << "\n";

    pp::cleanup();
}
