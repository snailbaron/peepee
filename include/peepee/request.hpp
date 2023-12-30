#pragma once

#include <peepee/headers.hpp>
#include <peepee/response.hpp>

#include <curl/curl.h>

#include <cstddef>
#include <filesystem>
#include <map>
#include <span>
#include <string_view>
#include <utility>
#include <vector>

namespace pp {

enum class Method {
    GET,
    OPTIONS,
    HEAD,
    POST,
    PUT,
    PATCH,
    DELETE,
};

struct File {
    std::string name;
    std::filesystem::path path;
    std::string contentType;
    std::vector<std::pair<std::string, std::string>> headers;
};

struct RequestOptions {
    Method method = Method::GET;
    std::string url;
    std::vector<std::pair<std::string, std::string>> params;
    std::span<std::byte> data;
    std::map<std::string, std::string> headers;
    //std::vector<std::pair<std::string, std::string>> cookies;
    //std::vector<File> files;
    //float timeoutSeconds = 0.f;
    bool allowRedirects = true;
};

class Request {
public:
    Request(const RequestOptions& options);
    Request(const Request& other);
    Request(Request&& other) noexcept;
    ~Request();

    Request& operator=(const Request& other);
    Request& operator=(Request&& other) noexcept;

    Response send() const;

private:
    static size_t writeData(void* buffer, size_t, size_t nmemb, void* userp);
    static size_t writeHeaders(void* buffer, size_t, size_t nmemb, void* userp);

    CURL* _handle = nullptr;
    Headers _headers;
};

Response request(const RequestOptions& options);

} // namespace pp
