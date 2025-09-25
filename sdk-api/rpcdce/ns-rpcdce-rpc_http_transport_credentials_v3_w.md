# RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W structure

## Description

The **RPC_HTTP_TRANSPORT_CREDENTIALS_V3** structure defines additional credentials to authenticate to an RPC proxy server or HTTP proxy server when using RPC/HTTP.

**RPC_HTTP_TRANSPORT_CREDENTIALS_V3** extends [RPC_HTTP_TRANSPORT_CREDENTIALS_V2](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_v2_a) by allowing arbitrary credential forms to be used.

## Members

### `TransportCredentials`

A pointer to an opaque authentication handle in the form of an [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle) structure.

### `Flags`

A set of flags that can be combined with the bitwise OR operator.

| Value | Meaning |
| --- | --- |
| **RPC_C_HTTP_FLAG_USE_SSL** | Instructs RPC to use SSL to communicate with the RPC Proxy. |
| **RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME** | When set, RPC chooses the first scheme in the **AuthnSchemes** array and attempts to authenticate to the RPC Proxy. If the RPC Proxy does not support the selected authentication scheme, the call fails. When not set, the RPC client queries the RPC Proxy for supported authentication schemes, and chooses one. |

### `AuthenticationTarget`

Specifies the authentication target.

Should be set to one or both of the following values:

| Value | Meaning |
| --- | --- |
| **RPC_C_HTTP_AUTHN_TARGET_SERVER** | Authenticate against the RPC Proxy, which is the HTTP Server from an HTTP perspective. This is the most common value. |
| **RPC_C_HTTP_AUTHN_TARGET_PROXY** | Authenticate against the HTTP Proxy. This value is uncommon. |

### `NumberOfAuthnSchemes`

The number of elements in the **AuthnScheme** array.

### `AuthnSchemes`

A pointer to an array of authentication schemes the client is willing to use. Each element of the array can contain one of the following constants:

#### RPC_C_HTTP_AUTHN_SCHEME_BASIC

#### RPC_C_HTTP_AUTHN_SCHEME_NTLM

#### RPC_C_HTTP_AUTHN_SCHEME_PASSPORT

#### RPC_C_HTTP_AUTHN_SCHEME_DIGEST

#### RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE

 RPC_C_HTTP_AUTHN_SCHEME_PASSPORT, RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE and RPC_C_HTTP_AUTHN_SCHEME_DIGEST are defined as constants, but not currently supported. Callers should not specify them; doing so results in RPC_S_CANNOT_SUPPORT error. Each constant can be specified once. RPC does not verify this restriction for performance reasons, but specifying a constant more than once produces undefined results.

The algorithm for choosing the actual authentication scheme is as follows:

 If RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME is specified, the first authentication scheme is chosen. If it is not supported by the server, the connection establishment fails. If RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME is not specified, the RPC client first attempts anonymous connection to the RPC Proxy. If IIS returns authentication challenge, the RPC client chooses the authentication scheme preferred by the server if it is also in the **AuthnScheme** array. If the scheme preferred by the server is not in the **AuthnScheme** array, the **AuthnScheme** array will be traversed from start to finish, and if a scheme is found that is also supported by the server, that authentication scheme is used.

### `ServerCertificateSubject`

Contains an optional string with the expected server principal name. The principal name is in the same format as that generated for [RpcCertGeneratePrincipalName](https://learn.microsoft.com/windows/desktop/api/rpcssl/nf-rpcssl-rpccertgenerateprincipalname) (see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names) for more information). This member is used only when SSL is used. In such cases, the server certificate is checked against the generated principal name. If they do not match, an error is returned. This member enables clients to authenticate the RPC Proxy.

### `ProxyCredentials`

A pointer to an opaque authentication handle in the form of an [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle) structure when authenticating against an HTTP proxy server. **ProxyCredentials** is only valid when **AuthenticationTarget** contains **RPC_C_HTTP_AUTHN_TARGET_PROXY**.

### `NumberOfProxyAuthnSchemes`

The number of elements in the **ProxyAuthnSchemes** array when authenticating against an HTTP proxy server. **NumberOfProxyAuthnSchemes** is only valid when **AuthenticationTarget** contains **RPC_C_HTTP_AUTHN_TARGET_PROXY**.

### `ProxyAuthnSchemes`

A pointer to an array of authentication schemes the client is willing to use when authenticating against an HTTP proxy server. Each element of the array can contain one of the following constants. **ProxyAuthnSchemes** is only valid when **AuthenticationTarget** contains **RPC_C_HTTP_AUTHN_TARGET_PROXY**.

#### RPC_C_HTTP_AUTHN_SCHEME_BASIC

#### RPC_C_HTTP_AUTHN_SCHEME_NTLM

#### RPC_C_HTTP_AUTHN_SCHEME_PASSPORT

#### RPC_C_HTTP_AUTHN_SCHEME_DIGEST

#### RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE

##### - AuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_BASIC

##### - AuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_DIGEST

##### - AuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE

##### - AuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_NTLM

##### - AuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_PASSPORT

##### - ProxyAuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_BASIC

##### - ProxyAuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_DIGEST

##### - ProxyAuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE

##### - ProxyAuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_NTLM

##### - ProxyAuthnSchemes.RPC_C_HTTP_AUTHN_SCHEME_PASSPORT

## Remarks

If the **TransportCredentials** member is **NULL** and the authentication scheme is NTLM, the credentials of the currently logged on user are used. To avoid exposing user credentials on the network through a weak LM hash, user logon credentials are used only if one or both of the following conditions are true:

* Caller requested use of SSL and used the **ServerCertificateSubject** member. This scenario guarantees credentials are protected both in transit and at the final destination, even if a weak hash is used.
* The lncompatibilitylevel key is set to 2 or higher. This causes the NTLM security provider to emit or respond to only the strong NT hash, not the weak LM hash. In addition, customers are encouraged to use level 3 or higher, which will attempt NTLMv2.

If the Unicode version of the [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa) function is used, Unicode versions of the **RPC_HTTP_TRANSPORT_CREDENTIALS_V3** and [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a) structures must also be provided, and the **Flags** member in **TransportCredentials** must be set to SEC_WINNT_AUTH_IDENTITY_UNICODE.
If the ANSI version of the **RpcBindingSetAuthInfoEx** function is used, ANSI versions of **RPC_HTTP_TRANSPORT_CREDENTIALS_V3** and **SEC_WINNT_AUTH_IDENTITY** structures must be provided, and the **Flags** member in **TransportCredentials** must be set to SEC_WINNT_AUTH_IDENTITY_ANSI.

## See also

[Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names)

[RPC_HTTP_TRANSPORT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_a)

[RPC_HTTP_TRANSPORT_CREDENTIALS_V2](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_v2_a)

[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos)

[RPC_SECURITY_QOS_V2](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v2_a)

[RPC_SECURITY_QOS_V3](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v3_a)

[Remote Procedure Calls Using RPC over HTTP](https://learn.microsoft.com/windows/desktop/Rpc/remote-procedure-calls-using-rpc-over-http)

[RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa)

[RpcCertGeneratePrincipalName](https://learn.microsoft.com/windows/desktop/api/rpcssl/nf-rpcssl-rpccertgenerateprincipalname)

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a)