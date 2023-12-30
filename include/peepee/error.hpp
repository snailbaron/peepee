#pragma once

#include <e.hpp>

#include <curl/curl.h>

#include <source_location>

namespace pp {

class Check final {
public:
    Check(std::source_location sourceLocation = std::source_location::current())
        : _sourceLocation(sourceLocation)
    { }

    Check&& operator<<(CURLcode code) &&;

private:
    std::source_location _sourceLocation;
};

Check check(std::source_location sourceLocation = std::source_location::current());

} // namespace pp
