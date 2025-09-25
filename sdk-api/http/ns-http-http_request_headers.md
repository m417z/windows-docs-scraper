# HTTP_REQUEST_HEADERS structure

## Description

The
**HTTP_REQUEST_HEADERS** structure contains headers sent with an HTTP request.

## Members

### `UnknownHeaderCount`

A number of unknown headers sent with the HTTP request. This number is the size of the array pointed to by the **pUnknownHeaders** member.

### `pUnknownHeaders`

A pointer to an array of
[HTTP_UNKNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_unknown_header) structures. This array contains one structure for each of the unknown headers sent in the HTTP request.

### `TrailerCount`

This member is reserved and must be zero.

### `pTrailers`

This member is reserved and must be **NULL**.

### `KnownHeaders`

Fixed-size array of
[HTTP_KNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_known_header) structures. The
[HTTP_HEADER_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id) enumeration provides a mapping from header types to array indexes. If a known header of a given type is included in the HTTP request, the array element at the index that corresponds to that type specifies the header value. Those elements of the array for which no corresponding headers are present contain a zero-valued **RawValueLength** member. Use **RawValueLength** to determine the end of the header string pointed to by **pRawValue**, rather than relying on the string to have a terminating null.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_KNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_known_header)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_UNKNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_unknown_header)