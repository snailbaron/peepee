#include <peepee/request.hpp>

#include <peepee/error.hpp>

#include <iostream>
#include <sstream>

namespace pp {

Request::Request(const RequestOptions& options)
    : _handle(curl_easy_init())
{
    check << curl_easy_setopt(_handle, CURLOPT_URL, options.url.c_str());
    check << curl_easy_setopt(
        _handle, CURLOPT_FOLLOWLOCATION, options.allowRedirects);
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
    check << curl_easy_setopt(_handle, CURLOPT_ERRORBUFFER, errorBuffer.data());

    auto responseData = std::ostringstream{};
    check << curl_easy_setopt(_handle, CURLOPT_WRITEFUNCTION, writeData);
    check << curl_easy_setopt(_handle, CURLOPT_WRITEDATA, &responseData);

    check << curl_easy_perform(_handle);

    long responseCode = 0;
    check << curl_easy_getinfo(_handle, CURLINFO_RESPONSE_CODE, &responseCode);

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
