# HTTP_REQUEST_AUTH_INFO structure

## Description

The **HTTP_REQUEST_AUTH_INFO** structure contains the authentication status of the request with a handle to the client token that the receiving process can use to impersonate the authenticated client.

This structure is contained in the [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_info) structure.

## Members

### `AuthStatus`

A member of the [HTTP_AUTH_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_auth_status) enumeration that indicates the final authentication status of the request.

If the authentication status is not **HttpAuthStatusSuccess**, applications should disregard members of this structure except **AuthStatus**, **SecStatus**, and **AuthType**.

### `SecStatus`

A [SECURITY_STATUS](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) value that indicates the security failure status when the **AuthStatus** member is **HttpAuthStatusFailure**.

### `Flags`

The authentication flags that indicate the following authentication attributes:

| Attribute | Meaning |
| --- | --- |
| **HTTP_REQUEST_AUTH_FLAG_TOKEN_FOR_CACHED_CRED** | The provided token is for NTLM and is based on a cached credential of a Keep Alive (KA) connection. |

### `AuthType`

A member of the [HTTP_REQUEST_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_request_auth_type) enumeration that indicates the authentication scheme attempted or established for the request.

### `AccessToken`

A handle to the client token that the receiving process can use to impersonate the authenticated client.

The handle to the token should be closed by calling [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when it is no longer required. This token is valid only for the lifetime of the request. Applications can regenerate the initial 401 challenge to reauthenticate when the token expires.

### `ContextAttributes`

The client context attributes for the access token.

### `PackedContextLength`

The length, in bytes, of the **PackedContext**.

### `PackedContextType`

The type of context in the **PackedContext** member.

### `PackedContext`

The security context for the authentication type.

Applications can query the attributes of the packed context by calling the SSPI [QueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) API. However, applications must acquire a credential handle for the security package for the indicated AuthType.

Application should call the SSPI [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) API to free the serialized context when it is no longer required.

### `MutualAuthDataLength`

The length, in bytes, of the **pMutualAuthData** member.

### `pMutualAuthData`

The Base64 encoded mutual authentication data used in the WWW-Authenticate header.

### `PackageNameLength`

### `pPackageName`

## Remarks

Starting with HTTP version 2.0, the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure contains an [HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_info) structure. The **pVoid** member of the **HTTP_REQUEST_INFO** structure points to the **HTTP_REQUEST_AUTH_INFO** when the request information type is **HttpRequestInfoTypeAuth**.

When the application receives a request with this structure and the request has not been authenticated, it can send the initial 401 challenge with the desired set of WWW-Authenticate headers in the [HTTP_MULTIPLE_KNOWN_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_multiple_known_headers) structure. When the HTTP Server API completes the authentication handshake, it fills the **HTTP_REQUEST_AUTH_INFO** structure and passes it to the application with the request again. The handle to the access token that represents the client identity is provided in this structure by the HTTP Server API.

Context Attributes

 The **ContextAttributes** member is provided for SSPI based schemes. For example, SSPI applications can determine whether **ASC_RET_MUTUAL_AUTH** is set for a mutually authenticated session.

The HTTP Server API does not provide the expiration time for the context in the **PackedContext** member. Applications may require the expiration time in specific circumstances, for example, when NTLM credential caching is enabled and the application queries for the expiration time for a cached context. If the server application requires the expiration time for the underlying client context associated with the access token, it can receive the packed context and call [QueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) with the **SECPKG_ATTR_LIFESPAN**.

Mutual Authentication Data

By default, the HTTP Server API ensures that the mutual authentication data is added to the final 200 response; in general, server applications are not responsible for sending the mutual authentication data.

However, applications can receive the mutual authentication data and send it with the final response. When the **ReceiveMutualAuth** member of the [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) structure is set to true, applications receive the server credentials for mutual authentication along with the authenticated request.

The mutual authentication data provided in the **pMutualAuthData** member contains the exact value of WWW-Authenticate header without the header name. For example, **pMutualAuthData** points to "Negotiate ade02938481eca". The application builds the WWW-Authenticate header by appending the provided **pMutualAuthData** as a response header value.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_info)

[HTTP_REQUEST_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_v2)