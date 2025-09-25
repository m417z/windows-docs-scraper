# HTTP_AUTH_STATUS enumeration

## Description

The **HTTP_AUTH_STATUS** enumeration defines the authentication state of a request.

This enumeration is used in the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure.

## Constants

### `HttpAuthStatusSuccess`

The request was successfully authenticated for the authentication type indicated in the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure.

### `HttpAuthStatusNotAuthenticated`

Authentication was configured on the URL group for this request, however, the HTTP Server API did not handle the authentication. This could be because of one of the following reasons:

* The scheme defined in the [HttpHeaderAuthorization](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_header_id) header of the request is not supported by the HTTP Server API, or it is not enabled on the URL Group. If the scheme is not enabled, the **AuthType** member of [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) is set to the appropriate type, otherwise **AuthType** will have the value [HttpRequestAuthTypeNone](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_request_auth_type).
* The authorization header is not present, however, authentication is enabled on the URL Group.

The application should either proceed with its own authentication or respond with the initial 401 challenge containing the desired set of authentication schemes.

### `HttpAuthStatusFailure`

Authentication for the authentication type listed in the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure failed, possibly due to one of the following reasons:

* The Security Service Provider Interface (SSPI) based authentication scheme failed to successfully return from a call to [AcceptSecurityContext](https://learn.microsoft.com/previous-versions/windows/embedded/ms937012(v=msdn.10)). The error returned [AcceptSecurityContext](https://learn.microsoft.com/previous-versions/windows/embedded/ms937012(v=msdn.10)) is indicated in the **SecStatus** member of the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure.
* The finalized client context is for a Null NTLM session. Null sessions are treated as authentication failures.
* The call to **LogonUser** failed for the Basic authentication.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info)