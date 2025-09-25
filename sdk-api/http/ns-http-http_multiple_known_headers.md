# HTTP_MULTIPLE_KNOWN_HEADERS structure

## Description

The **HTTP_MULTIPLE_KNOWN_HEADERS** structure specifies the headers that are included in an HTTP response when more than one header is required.

## Members

### `HeaderId`

A member of the [HTTP_HEADER_ID](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id) enumeration specifying the response header ID.

### `Flags`

The flags corresponding to the response header in the **HeaderId** member. This member is used only when the WWW-Authenticate header is present. This can be zero or the following:

| Flag | Meaning |
| --- | --- |
| **HTTP_RESPONSE_INFO_FLAGS_PRESERVE_ORDER** | The specified order of authentication schemes is preserved on the challenge response. |

### `KnownHeaderCount`

The number of elements in the array specified in the **KnownHeaders** member.

### `KnownHeaders`

A pointer to the first element in the array of [HTTP_KNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_known_header) structures.

## Remarks

The HTTP version 1.0 API allows applications to send only one known response header with the response. Starting with the HTTP version 2.0 API, applications are enabled to send multiple known response headers.

The **pInfo** member of the [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structure points to this structure when the application provides multiple known headers on a response. The **HTTP_RESPONSE_INFO** structure extends the [HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response) structure starting with HTTP version 2.0.

The **HTTP_MULTIPLE_KNOWN_HEADERS** structure enables server applications to send multiple authentication challenges to the client.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info)

[HTTP_RESPONSE_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v2)