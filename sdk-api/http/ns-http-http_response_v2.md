# HTTP_RESPONSE_V2 structure

## Description

The **HTTP_RESPONSE_V2** structure extends the HTTP version 1.0 response structure with more information for the response.

Do not use **HTTP_RESPONSE_V2** directly in your code; use [HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response) instead to ensure that the proper version, based on the operating system the code is compiled under, is used.

## Members

### `ResponseInfoCount`

The number of [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structures in the array pointed to by **pResponseInfo**.

The count of the HTTP_RESPONSE_INFO elements in the array pointed to by **pResponseInfo**.

### `pResponseInfo`

A pointer to an array of [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structures containing more information about the request.

### `_HTTP_RESPONSE_V1`

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers)

[HTTP_RESPONSE_V1](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v1)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)