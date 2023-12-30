#pragma once

#include <curl/curl.h>

#include <concepts>
#include <memory>
#include <string_view>

namespace pp {

class Headers {
public:
    Headers() = default;

    template <std::ranges::input_range Hs>
    Headers(const Hs& headers)
    {
        for (const auto& [key, value] : headers) {
            append(key, value);
        }
    }

    void append(std::string_view key, std::string_view value);

private:
    std::unique_ptr<struct curl_slist, void(*)(struct curl_slist*)> _list
        {nullptr, curl_slist_free_all};

    friend class Request;
};

} // namespace pp
