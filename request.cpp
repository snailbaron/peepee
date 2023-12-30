#include <peepee/request.hpp>

#include <peepee/error.hpp>

#include <format>
#include <iostream>
#include <sstream>

namespace pp {

namespace {

std::string urlEncode(std::string_view string)
{
    char* s = curl_easy_escape(nullptr, string.data(), (int)string.length());
    auto result = std::string{s};
    curl_free(s);
    return result;
}

std::string encodeUrl(
    std::string_view url,
    const std::vector<std::pair<std::string, std::string>>& params)
{
    auto s = std::ostringstream{};
    s << url;
    char separator = '?';
    for (const auto& [key, value] : params) {
        s << separator << urlEncode(key) << "=" << urlEncode(value);
        separator = '&';
    }

    return s.str();
}

} // namespace

Request::Request(const RequestOptions& options)
    : _handle(curl_easy_init())
    , _headers(options.headers)
{
    auto url = encodeUrl(options.url, options.params);
    std::cerr << "URL: " << url << "\n";
    check() << curl_easy_setopt(_handle, CURLOPT_URL, url.c_str());
    check() << curl_easy_setopt(
        _handle, CURLOPT_FOLLOWLOCATION, options.allowRedirects);
    check() << curl_easy_setopt(
        _handle, CURLOPT_HTTPHEADER, _headers._list.get());
}

Request::Request(const Request& other)
    : _handle(curl_easy_duphandle(other._handle))
{ }

Request::Request(Request&& other) noexcept
    : _handle(other._handle)
{
    other._handle = nullptr;
}

Request::~Request()
{
    // OK to call with null pointer
    curl_easy_cleanup(_handle);
}

Request& Request::operator=(const Request& other)
{
    if (&other != this) {
        curl_easy_cleanup(_handle);
        _handle = curl_easy_duphandle(other._handle);
    }
    return *this;
}

Request& Request::operator=(Request&& other) noexcept
{
    if (&other != this) {
        curl_easy_cleanup(_handle);
        _handle = other._handle;
        other._handle = nullptr;
    }
    return *this;
}

Response Request::send() const
{
    auto errorBuffer = std::string(CURL_ERROR_SIZE, '\0');
    check() << curl_easy_setopt(_handle, CURLOPT_ERRORBUFFER, errorBuffer.data());

    auto responseData = std::ostringstream{};
    check() << curl_easy_setopt(_handle, CURLOPT_WRITEFUNCTION, writeData);
    check() << curl_easy_setopt(_handle, CURLOPT_WRITEDATA, &responseData);

    check() << curl_easy_perform(_handle);

    long responseCode = 0;
    check() << curl_easy_getinfo(_handle, CURLINFO_RESPONSE_CODE, &responseCode);

    return Response{
        .code = responseCode,
        .data = responseData.str(),
    };
}

size_t Request::writeData(void* buffer, size_t, size_t nmemb, void* userp)
{
    auto& stream = *reinterpret_cast<std::ostringstream*>(userp);
    auto data = std::string_view{reinterpret_cast<char*>(buffer), nmemb};
    stream << data;
    return nmemb;
}

size_t Request::writeHeaders(void* buffer, size_t, size_t nmemb, void*)
{
    auto header = std::string_view{reinterpret_cast<char*>(buffer), nmemb};
    std::cerr << "debug header: " << header;
    return nmemb;
}

Response request(const RequestOptions& options)
{
    return Request{options}.send();
}

} // namespace pp
