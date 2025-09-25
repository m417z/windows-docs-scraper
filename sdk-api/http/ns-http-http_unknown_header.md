# HTTP_UNKNOWN_HEADER structure

## Description

The
**HTTP_UNKNOWN_HEADER** structure contains the name and value for a header in an HTTP request or response whose name does not appear in the enumeration.

## Members

### `NameLength`

The size, in bytes, of the data pointed to by the **pName** member not counting a terminating null.

### `RawValueLength`

The size, in bytes, of the data pointed to by the **pRawValue** member, in bytes.

### `pName`

A pointer to a string of octets that specifies the header name. Use **NameLength** to determine the end of the string, rather than relying on a terminating **null**.

### `pRawValue`

A pointer to a string of octets that specifies the values for this header. Use **RawValueLength** to determine the end of the string, rather than relying on a terminating **null**.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_HEADER_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id)

[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers)

[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers)