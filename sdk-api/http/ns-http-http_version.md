# HTTP_VERSION structure

## Description

The
**HTTP_VERSION** structure defines a version of the HTTP protocol that a request requires or a response provides. This is not to be confused with the version of the HTTP Server API used, which is stored in an
[HTTPAPI_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-httpapi_version) structure.

## Members

### `MajorVersion`

Major version of the HTTP protocol.

### `MinorVersion`

Minor version of the HTTP protocol.

## Remarks

For more information about the HTTP protocol, see
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

The following macros define various versions of the HTTP protocol:"#define HTTP_VERSION_UNKNOWN { 0, 0 }""#define HTTP_VERSION_0_9 { 0, 9 }""#define HTTP_VERSION_1_0 { 1, 0 }""#define HTTP_VERSION_1_1 { 1, 1 }"

The HTTP Server API provides a number of macros that can be used to evaluate the value of an HTTP_VERSION structure; For more information, see
[HTTP Server API Version 1.0 Macros](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-macros).

**Note** The HTTP Server API rejects a version of HTTP larger than 65,535 in either the major or minor portion. If a request includes such a version number, the HTTP Server API discards it and returns a response with status 400 ("Bad Request").

## See also

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)