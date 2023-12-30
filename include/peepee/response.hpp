#pragma once

#include <string>

namespace pp {

struct Response {
    long code = 0;
    std::string data;
};

} // namespace pp
