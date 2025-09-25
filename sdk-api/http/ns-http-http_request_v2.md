# HTTP_REQUEST_V2 structure

## Description

The **HTTP_REQUEST_V2** structure extends the [HTTP_REQUEST_V1](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_v1) request structure with more information about the request.

Do not use **HTTP_REQUEST_V2** directly in your code; use [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) instead to ensure that the proper version, based on the operating system the code is compiled under, is used.

## Members

### `RequestInfoCount`

The number of [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_info) structures in the array pointed to by **pRequestInfo**.

### `pRequestInfo`

A pointer to an array of [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_info) structures that contains additional information about the request.

### `_HTTP_REQUEST_V1`

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_COOKED_URL](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cooked_url)

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_REQUEST_V1](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_v1)

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HTTP_SSL_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_info)

[HTTP_TRANSPORT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_transport_address)

[HTTP_VERB](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_verb)

[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest)

[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)