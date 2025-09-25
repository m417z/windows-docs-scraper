## Description

The **HTTP_REQUEST_INFO_TYPE** enumeration defines the type of information contained in the [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_info) structure.

## Constants

### `HttpRequestInfoTypeAuth`

The requested information type is authentication. The *pInfo* member of the [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_info) structure points to a [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_auth_info) structure.

### `HttpRequestInfoTypeChannelBind`

### `HttpRequestInfoTypeSslProtocol`

### `HttpRequestInfoTypeSslTokenBindingDraft`

### `HttpRequestInfoTypeSslTokenBinding`

### `HttpRequestInfoTypeRequestTiming`

The requested information type is timing. The *pInfo* member of the [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_info) structure points to a [HTTP_REQUEST_TIMING_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_timing_info) structure.

### `HttpRequestInfoTypeTcpInfoV0`

### `HttpRequestInfoTypeRequestSizing`

### `HttpRequestInfoTypeQuicStats`

### `HttpRequestInfoTypeTcpInfoV1`

## See also

* [HTTP_REQUEST_INFO structure](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_info)
* [HTTP Server API version 2.0 enumeration types](https://learn.microsoft.com/windows/win32/http/http-server-api-version-2-0-enumeration-types)