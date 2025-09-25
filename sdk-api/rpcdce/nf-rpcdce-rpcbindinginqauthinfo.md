# RpcBindingInqAuthInfo function

## Description

The
**RpcBindingInqAuthInfo** function returns authentication and authorization information from a binding handle.

## Parameters

### `Binding`

Server binding handle from which authentication and authorization information is returned.

### `ServerPrincName`

Returns a pointer to a pointer to the expected principal name of the server referenced in *Binding*. The content of the returned name and its syntax are defined by the authentication service in use.

Specify a null value to prevent
**RpcBindingInqAuthInfo** from returning the *ServerPrincName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

### `AuthnLevel`

Returns a pointer set to the level of authentication used for remote procedure calls made using *Binding*. See Note.

Specify a null value to prevent the function from returning the *AuthnLevel* parameter.

The level returned in the *AuthnLevel* parameter may be different from the level specified when the client called the
[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) function. This discrepancy occurs when the RPC run-time library does not support the authentication level specified by the client and automatically upgrades to the next higher authentication level.

### `AuthnSvc`

Returns a pointer set to the authentication service specified for remote procedure calls made using *Binding*. See Note.

Specify a null value to prevent
**RpcBindingInqAuthInfo** from returning the *AuthnSvc* parameter.

### `AuthIdentity`

Returns a pointer to a handle to the data structure that contains the client's authentication and authorization credentials specified for remote procedure calls made using *Binding*.

Specify a null value to prevent
**RpcBindingInqAuthInfo** from returning the *AuthIdentity* parameter.

### `AuthzSvc`

Returns a pointer set to the authorization service requested by the client application that made the remote procedure call on *Binding* See Note.

Specify a null value to prevent
**RpcBindingInqAuthInfo** from returning the *AuthzSvc* parameter.

**Note** For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_BINDING_HAS_NO_AUTH** | Binding has no authentication information. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A client application calls the
**RpcBindingInqAuthInfo** function to view the authentication and authorization information associated with a server binding handle. A similar function,
[RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa) additionally provides security quality-of-service information on the binding handle.

The RPC run-time library allocates memory for the returned *ServerPrincName* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function for that returned argument string.

## See also

[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient)

[RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa)

[RpcBindingInqOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqoption)

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)