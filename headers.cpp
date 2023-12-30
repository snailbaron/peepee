#include <peepee/headers.hpp>

#include <sstream>

namespace pp {

namespace {

std::string joinKeyValue(std::string_view key, std::string_view value)
{
    auto result = std::ostringstream{};
    result << key << ":";
    if (!value.empty()) {
        result << " " << value;
    }
    return result.str();
}

} // namespace

void Headers::append(std::string_view key, std::string_view value)
{
    auto headerString = joinKeyValue(key, value);
    _list.reset(curl_slist_append(_list.get(), headerString.c_str()));
}

} // namespace pp
