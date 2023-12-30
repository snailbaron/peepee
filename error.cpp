#include <peepee/error.hpp>

#include <ostream>

namespace pp {

namespace {

class CurlCodeName {
public:
    CurlCodeName(CURLcode code)
        : _code(code)
    { }

private:
    friend std::ostream& operator<<(
        std::ostream& output, const CurlCodeName& curlCodeName)
    {
        switch (curlCodeName._code) {
            case CURLE_OK: return output << "CURLE_OK";
            case CURLE_UNSUPPORTED_PROTOCOL: return output << "CURLE_UNSUPPORTED_PROTOCOL";
            case CURLE_FAILED_INIT: return output << "CURLE_FAILED_INIT";
            case CURLE_URL_MALFORMAT: return output << "CURLE_URL_MALFORMAT";
            case CURLE_NOT_BUILT_IN: return output << "CURLE_NOT_BUILT_IN";
            case CURLE_COULDNT_RESOLVE_PROXY: return output << "CURLE_COULDNT_RESOLVE_PROXY";
            case CURLE_COULDNT_RESOLVE_HOST: return output << "CURLE_COULDNT_RESOLVE_HOST";
            case CURLE_COULDNT_CONNECT: return output << "CURLE_COULDNT_CONNECT";
            case CURLE_WEIRD_SERVER_REPLY: return output << "CURLE_WEIRD_SERVER_REPLY";
            case CURLE_REMOTE_ACCESS_DENIED: return output << "CURLE_REMOTE_ACCESS_DENIED";
            case CURLE_FTP_ACCEPT_FAILED: return output << "CURLE_FTP_ACCEPT_FAILED";
            case CURLE_FTP_WEIRD_PASS_REPLY: return output << "CURLE_FTP_WEIRD_PASS_REPLY";
            case CURLE_FTP_ACCEPT_TIMEOUT: return output << "CURLE_FTP_ACCEPT_TIMEOUT";
            case CURLE_FTP_WEIRD_PASV_REPLY: return output << "CURLE_FTP_WEIRD_PASV_REPLY";
            case CURLE_FTP_WEIRD_227_FORMAT: return output << "CURLE_FTP_WEIRD_227_FORMAT";
            case CURLE_FTP_CANT_GET_HOST: return output << "CURLE_FTP_CANT_GET_HOST";
            case CURLE_HTTP2: return output << "CURLE_HTTP2";
            case CURLE_FTP_COULDNT_SET_TYPE: return output << "CURLE_FTP_COULDNT_SET_TYPE";
            case CURLE_PARTIAL_FILE: return output << "CURLE_PARTIAL_FILE";
            case CURLE_FTP_COULDNT_RETR_FILE: return output << "CURLE_FTP_COULDNT_RETR_FILE";
            case CURLE_OBSOLETE20: return output << "CURLE_OBSOLETE20";
            case CURLE_QUOTE_ERROR: return output << "CURLE_QUOTE_ERROR";
            case CURLE_HTTP_RETURNED_ERROR: return output << "CURLE_HTTP_RETURNED_ERROR";
            case CURLE_WRITE_ERROR: return output << "CURLE_WRITE_ERROR";
            case CURLE_OBSOLETE24: return output << "CURLE_OBSOLETE24";
            case CURLE_UPLOAD_FAILED: return output << "CURLE_UPLOAD_FAILED";
            case CURLE_READ_ERROR: return output << "CURLE_READ_ERROR";
            case CURLE_OUT_OF_MEMORY: return output << "CURLE_OUT_OF_MEMORY";
            case CURLE_OPERATION_TIMEDOUT: return output << "CURLE_OPERATION_TIMEDOUT";
            case CURLE_OBSOLETE29: return output << "CURLE_OBSOLETE29";
            case CURLE_FTP_PORT_FAILED: return output << "CURLE_FTP_PORT_FAILED";
            case CURLE_FTP_COULDNT_USE_REST: return output << "CURLE_FTP_COULDNT_USE_REST";
            case CURLE_OBSOLETE32: return output << "CURLE_OBSOLETE32";
            case CURLE_RANGE_ERROR: return output << "CURLE_RANGE_ERROR";
            case CURLE_HTTP_POST_ERROR: return output << "CURLE_HTTP_POST_ERROR";
            case CURLE_SSL_CONNECT_ERROR: return output << "CURLE_SSL_CONNECT_ERROR";
            case CURLE_BAD_DOWNLOAD_RESUME: return output << "CURLE_BAD_DOWNLOAD_RESUME";
            case CURLE_FILE_COULDNT_READ_FILE: return output << "CURLE_FILE_COULDNT_READ_FILE";
            case CURLE_LDAP_CANNOT_BIND: return output << "CURLE_LDAP_CANNOT_BIND";
            case CURLE_LDAP_SEARCH_FAILED: return output << "CURLE_LDAP_SEARCH_FAILED";
            case CURLE_OBSOLETE40: return output << "CURLE_OBSOLETE40";
            case CURLE_FUNCTION_NOT_FOUND: return output << "CURLE_FUNCTION_NOT_FOUND";
            case CURLE_ABORTED_BY_CALLBACK: return output << "CURLE_ABORTED_BY_CALLBACK";
            case CURLE_BAD_FUNCTION_ARGUMENT: return output << "CURLE_BAD_FUNCTION_ARGUMENT";
            case CURLE_OBSOLETE44: return output << "CURLE_OBSOLETE44";
            case CURLE_INTERFACE_FAILED: return output << "CURLE_INTERFACE_FAILED";
            case CURLE_OBSOLETE46: return output << "CURLE_OBSOLETE46";
            case CURLE_TOO_MANY_REDIRECTS: return output << "CURLE_TOO_MANY_REDIRECTS";
            case CURLE_UNKNOWN_OPTION: return output << "CURLE_UNKNOWN_OPTION";
            case CURLE_SETOPT_OPTION_SYNTAX: return output << "CURLE_SETOPT_OPTION_SYNTAX";
            case CURLE_OBSOLETE50: return output << "CURLE_OBSOLETE50";
            case CURLE_OBSOLETE51: return output << "CURLE_OBSOLETE51";
            case CURLE_GOT_NOTHING: return output << "CURLE_GOT_NOTHING";
            case CURLE_SSL_ENGINE_NOTFOUND: return output << "CURLE_SSL_ENGINE_NOTFOUND";
            case CURLE_SSL_ENGINE_SETFAILED: return output << "CURLE_SSL_ENGINE_SETFAILED";
            case CURLE_SEND_ERROR: return output << "CURLE_SEND_ERROR";
            case CURLE_RECV_ERROR: return output << "CURLE_RECV_ERROR";
            case CURLE_OBSOLETE57: return output << "CURLE_OBSOLETE57";
            case CURLE_SSL_CERTPROBLEM: return output << "CURLE_SSL_CERTPROBLEM";
            case CURLE_SSL_CIPHER: return output << "CURLE_SSL_CIPHER";
            case CURLE_PEER_FAILED_VERIFICATION: return output << "CURLE_PEER_FAILED_VERIFICATION";
            case CURLE_BAD_CONTENT_ENCODING: return output << "CURLE_BAD_CONTENT_ENCODING";
            case CURLE_OBSOLETE62: return output << "CURLE_OBSOLETE62";
            case CURLE_FILESIZE_EXCEEDED: return output << "CURLE_FILESIZE_EXCEEDED";
            case CURLE_USE_SSL_FAILED: return output << "CURLE_USE_SSL_FAILED";
            case CURLE_SEND_FAIL_REWIND: return output << "CURLE_SEND_FAIL_REWIND";
            case CURLE_SSL_ENGINE_INITFAILED: return output << "CURLE_SSL_ENGINE_INITFAILED";
            case CURLE_LOGIN_DENIED: return output << "CURLE_LOGIN_DENIED";
            case CURLE_TFTP_NOTFOUND: return output << "CURLE_TFTP_NOTFOUND";
            case CURLE_TFTP_PERM: return output << "CURLE_TFTP_PERM";
            case CURLE_REMOTE_DISK_FULL: return output << "CURLE_REMOTE_DISK_FULL";
            case CURLE_TFTP_ILLEGAL: return output << "CURLE_TFTP_ILLEGAL";
            case CURLE_TFTP_UNKNOWNID: return output << "CURLE_TFTP_UNKNOWNID";
            case CURLE_REMOTE_FILE_EXISTS: return output << "CURLE_REMOTE_FILE_EXISTS";
            case CURLE_TFTP_NOSUCHUSER: return output << "CURLE_TFTP_NOSUCHUSER";
            case CURLE_OBSOLETE75: return output << "CURLE_OBSOLETE75";
            case CURLE_OBSOLETE76: return output << "CURLE_OBSOLETE76";
            case CURLE_SSL_CACERT_BADFILE: return output << "CURLE_SSL_CACERT_BADFILE";
            case CURLE_REMOTE_FILE_NOT_FOUND: return output << "CURLE_REMOTE_FILE_NOT_FOUND";
            case CURLE_SSH: return output << "CURLE_SSH";
            case CURLE_SSL_SHUTDOWN_FAILED: return output << "CURLE_SSL_SHUTDOWN_FAILED";
            case CURLE_AGAIN: return output << "CURLE_AGAIN";
            case CURLE_SSL_CRL_BADFILE: return output << "CURLE_SSL_CRL_BADFILE";
            case CURLE_SSL_ISSUER_ERROR: return output << "CURLE_SSL_ISSUER_ERROR";
            case CURLE_FTP_PRET_FAILED: return output << "CURLE_FTP_PRET_FAILED";
            case CURLE_RTSP_CSEQ_ERROR: return output << "CURLE_RTSP_CSEQ_ERROR";
            case CURLE_RTSP_SESSION_ERROR: return output << "CURLE_RTSP_SESSION_ERROR";
            case CURLE_FTP_BAD_FILE_LIST: return output << "CURLE_FTP_BAD_FILE_LIST";
            case CURLE_CHUNK_FAILED: return output << "CURLE_CHUNK_FAILED";
            case CURLE_NO_CONNECTION_AVAILABLE: return output << "CURLE_NO_CONNECTION_AVAILABLE";
            case CURLE_SSL_PINNEDPUBKEYNOTMATCH: return output << "CURLE_SSL_PINNEDPUBKEYNOTMATCH";
            case CURLE_SSL_INVALIDCERTSTATUS: return output << "CURLE_SSL_INVALIDCERTSTATUS";
            case CURLE_HTTP2_STREAM: return output << "CURLE_HTTP2_STREAM";
            case CURLE_RECURSIVE_API_CALL: return output << "CURLE_RECURSIVE_API_CALL";
            case CURLE_AUTH_ERROR: return output << "CURLE_AUTH_ERROR";
            case CURLE_HTTP3: return output << "CURLE_HTTP3";
            case CURLE_QUIC_CONNECT_ERROR: return output << "CURLE_QUIC_CONNECT_ERROR";
            case CURLE_PROXY: return output << "CURLE_PROXY";
            case CURLE_SSL_CLIENTCERT: return output << "CURLE_SSL_CLIENTCERT";
            case CURLE_UNRECOVERABLE_POLL: return output << "CURLE_UNRECOVERABLE_POLL";
            case CURL_LAST: break;
        }
        return output << "unknown (" << curlCodeName._code << ")";
    }

    CURLcode _code {};
};

} // namespace

Check&& Check::operator<<(CURLcode code) &&
{
    if (code != CURLE_OK) {
        const char* description = curl_easy_strerror(code);
        throw e::Error{_sourceLocation} <<
            CurlCodeName{code} << ": " << description;
    }
    return std::move(*this);
}

Check check(std::source_location sourceLocation)
{
    return Check{sourceLocation};
}

} // namespace pp
