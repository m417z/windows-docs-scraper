# RpcBindingInqAuthClientEx function

## Description

A server application calls the
**RpcBindingInqAuthClientEx** function to obtain extended information about the client program that made the remote procedure call.

## Parameters

### `ClientBinding`

Client binding handle of the client that made the remote procedure call. This value can be zero. See Remarks.

### `Privs`

Returns a pointer to a handle to the privileged information for the client application that made the remote procedure call on the *ClientBinding* binding handle. For **ncalrpc** calls, *Privs* contains a string with the client's principal name.

The server application must cast the *Privs* parameter to the data type specified by the *AuthnSvc* parameter. The data referenced by this argument is read-only and should not be modified by the server application. If the server wants to preserve any of the returned data, the server must copy the data into server-allocated memory.

For more information on SSPs, see
[Security Support Providers (SSPs)](https://learn.microsoft.com/windows/desktop/Rpc/security-support-providers-ssps-).

### `ServerPrincName`

Returns a pointer to a pointer to the server principal name specified by the server application that called the [RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo) function. The content of the returned name and its syntax are defined by the authentication service in use. For the SCHANNEL SSP, the principal name is in msstd format. For further information on msstd format, see
[Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names).

Specify a null value to prevent
**RpcBindingInqAuthClientEx** from returning the *ServerPrincName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

### `AuthnLevel`

Returns a pointer set to the level of authentication requested by the client application that made the remote procedure call on the *ClientBinding* binding handle. For a list of the RPC-supported authentication levels, see
[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants).

Specify a null value to prevent
**RpcBindingInqAuthClientEx** from returning the *AuthnLevel* parameter.

### `AuthnSvc`

Returns a pointer set to the authentication service requested by the client application that made the remote procedure call on the *ClientBinding* binding handle. For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

Specify a null value to prevent
**RpcBindingInqAuthClientEx** from returning the *AuthnSvc* parameter.

**Note** *AuthnSvc* corresponds to the **SECURITY_STATUS** returned by [QueryContextAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) on each certificate-based SSP for **SECPKG_ATTR_DCE_INFO** or **SECPKG_ATTR_REMOTE_CERT_CONTEXT**.

### `AuthzSvc`

Returns a pointer set to the authorization service requested by the client application that made the remote procedure call on the *Binding* binding handle. For a list of the RPC-supported authorization services, see
[Authorization-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authorization-service-constants) .

Specify a null value to prevent
**RpcBindingInqAuthClientEx** from returning the *AuthzSvc* parameter. This parameter is not used by the RPC_C_AUTHN_WINNT authentication service. The returned value will always be RPC_S_AUTHZ_NONE.

### `Flags`

Controls the format of the principal name. This parameter can be set to the following value.

| Value | Meaning |
| --- | --- |
| **RPC_C_FULL_CERT_CHAIN** | Passes back the principal name in [fullsic](https://learn.microsoft.com/windows/desktop/Rpc/principal-names) format. |

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_S_BINDING_HAS_NO_AUTH** | Binding has no authentication information. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls the
**RpcBindingInqAuthClientEx** function to obtain the principal name or privilege attributes of the authenticated client that made the remote procedure call. In addition,
**RpcBindingInqAuthClientEx** returns the authentication service, authentication level, and server principal name specified by the client. The server can use the returned data for authorization purposes.

The RPC run-time library allocates memory for the returned *ServerPrincName* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function for the returned argument string.

For synchronous RPC calls, the server application can use zero as the value for the *ClientBinding* parameter. Using zero retrieves the authentication and authorization information from the currently executing remote procedure call.

## See also

[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient)

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)