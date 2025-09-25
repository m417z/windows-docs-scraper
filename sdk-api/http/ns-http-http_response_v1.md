# HTTP_RESPONSE_V1 structure

## Description

The
**HTTP_RESPONSE_V1** structure contains data associated with an HTTP response.

Do not use **HTTP_RESPONSE_V1** directly in your code; use [HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response) instead to ensure that the proper version, based on the operating system the code is compiled under, is used.

## Members

### `Flags`

The optional logging flags change the default response behavior. These can be one of any of the [HTTP_RESPONSE_FLAG](https://learn.microsoft.com/windows/desktop/Http/http-response-flag--constants) values.

### `Version`

This member is ignored; the response is always an HTTP/1.1 response.

### `StatusCode`

Numeric status code that characterizes the result of the HTTP request (for example, 200 signifying "OK" or 404 signifying "Not Found"). For more information and a list of these codes, see Section 10 of
[RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

If a request is directed to a URL that is reserved but not registered, indicating that the appropriate application to handle it is not running, then the HTTP Server API itself returns a response with status code 400, signifying "Bad Request". This is transparent to the application. A code 400 is preferred here to 503 ("Server not available") because the latter is interpreted by some smart load balancers as an indication that the server is overloaded.

### `ReasonLength`

Size, in bytes, of the string pointed to by the **pReason** member not including the terminating null. May be zero.

### `pReason`

A pointer to a human-readable, null-terminated string of printable characters that characterizes the result of the HTTP request (for example, "OK" or "Not Found").

### `Headers`

An
[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers) structure that contains the headers used in this response.

### `EntityChunkCount`

A number of entity-body data blocks specified in the **pEntityChunks** array. This number cannot exceed 100. If the response has no entity body, this member must be zero.

### `pEntityChunks`

An array of
[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk) structures that together specify all the data blocks that make up the entity body of the response.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers)

[HTTP_RESPONSE_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v2)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)