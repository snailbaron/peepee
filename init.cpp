#include <peepee/init.hpp>

#include <peepee/error.hpp>

#include <curl/curl.h>

namespace pp {

void initialize(const InitializeOptions& options)
{
    check() << curl_global_init(
        options.initializeWin32Sockets * CURL_GLOBAL_WIN32 |
        options.initializeSSL * CURL_GLOBAL_SSL);
}

void cleanup()
{
    curl_global_cleanup();
}

} // namespace pp
