# HTTP_SERVER_AUTHENTICATION_INFO structure

## Description

The **HTTP_SERVER_AUTHENTICATION_INFO** structure is used to enable server-side authentication on a URL group or server session. This structure is also used to query the existing authentication schemes enabled for a URL group or server session.

This structure must be used when setting or querying the [HttpServerAuthenticationProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL group, or server session.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure that specifies if the property is present.

### `AuthSchemes`

The supported authentication schemes. This can be one or more of the following:

| Authentication Scheme | Meaning |
| --- | --- |
| **HTTP_AUTH_ENABLE_BASIC** | Basic authentication is enabled. |
| **HTTP_AUTH_ENABLE_DIGEST** | Digest authentication is enabled. |
| **HTTP_AUTH_ENABLE_NTLM** | NTLM authentication is enabled. |
| **HTTP_AUTH_ENABLE_NEGOTIATE** | Negotiate authentication is enabled. |
| **HTTP_AUTH_ENABLE_KERBEROS** | Kerberos authentication is enabled. |
| **HTTP_AUTH_ENABLE_ALL** | All types of authentication are enabled. |

### `ReceiveMutualAuth`

A Boolean value that indicates, if **True**, that the client application receives the server credentials for mutual authentication with the authenticated request. If **False**, the client application does not receive the credentials.

Be aware that this option is set for all requests served by the associated request queue.

### `ReceiveContextHandle`

A Boolean value that indicates, if **True**, that the finalized client context is serialized and passed to the application with the request. If **False**, the application does not receive the context. This handle can be used to query context attributes.

### `DisableNTLMCredentialCaching`

A Boolean value that indicates, if **True**, that the NTLM credentials are not cached. If **False**, the default behavior is preserved.

By default, HTTP caches the client context for Keep Alive (KA) connections for the NTLM scheme if the request did not originate from a proxy.

### `ExFlags`

Optional authentication flags. Can be one or more of the following possible values:

| Value | Meaning |
| --- | --- |
| **HTTP_AUTH_EX_FLAG_ENABLE_KERBEROS_CREDENTIAL_CACHING** | If set, the Kerberos authentication credentials are cached. Kerberos or Negotiate authentication must be enabled by **AuthSchemes**. |
| **HTTP_AUTH_EX_FLAG_CAPTURE_CREDENTIAL** | If set, the HTTP Server API captures the caller's credentials and uses them for Kerberos or Negotiate authentication. Kerberos or Negotiate authentication must be enabled by **AuthSchemes**. |

### `DigestParams`

The [HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_digest_params) structure that provides the domain and realm for the digest challenge.

### `BasicParams`

The [HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_basic_params) structure that provides the realm for the basic challenge.

## Remarks

The **HTTP_SERVER_AUTHENTICATION_INFO** structure is included in the HTTP request if authentication has been configured on the associated URL group. The original HTTP authentication header received from the client is always included in the HTTP request, regardless of the authentication status.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_AUTH_ENABLE](https://learn.microsoft.com/windows/desktop/Http/http-auth-enable--constants)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)