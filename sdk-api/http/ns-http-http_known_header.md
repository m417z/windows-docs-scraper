# HTTP_KNOWN_HEADER structure

## Description

The
**HTTP_KNOWN_HEADER** structure contains the header values for a known header from an HTTP request or HTTP response.

## Members

### `RawValueLength`

Size, in bytes, of the 8-bit string pointed to by the **pRawValue** member, not counting a terminating null character, if present. If **RawValueLength** is zero, then the value of the **pRawValue** element is meaningless.

### `pRawValue`

Pointer to the text of this HTTP header. Use **RawValueLength** to determine where this text ends rather than relying on the string to have a terminating null. The format of the header text is specified in
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

## Remarks

In the HTTP Server API, known headers are defined as those that are enumerated in the
[HTTP_HEADER_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id) enumeration type. Be aware that there are different lists of different sizes for request and response headers.

For more information about the structure and usage of HTTP headers, see the
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_HEADER_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id)

[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers)

[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers)