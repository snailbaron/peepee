#pragma once

#include <e.hpp>

#include <curl/curl.h>

namespace pp {

class Check {
private:
    friend Check& operator<<(Check& check, CURLcode code)
    {
        if (code != CURLE_OK) {
            throw e::Error{} << "curl error: " << code;
        }
        return check;
    }
};

inline Check check;

} // namespace pp
