# HTTP_REQUEST_AUTH_TYPE enumeration

## Description

The **HTTP_REQUEST_AUTH_TYPE** enumeration defines the authentication types supported by the HTTP Server API.

This enumeration is used in the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure.

## Constants

### `HttpRequestAuthTypeNone:0`

No authentication is attempted for the request.

### `HttpRequestAuthTypeBasic`

Basic authentication is attempted for the request.

### `HttpRequestAuthTypeDigest`

 Digest authentication is attempted for the request.

### `HttpRequestAuthTypeNTLM`

 NTLM authentication is attempted for the request.

### `HttpRequestAuthTypeNegotiate`

 Negotiate authentication is attempted for the request.

### `HttpRequestAuthTypeKerberos`

Kerberos authentication is attempted for the request.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info)