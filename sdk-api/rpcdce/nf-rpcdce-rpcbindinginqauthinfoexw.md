# RpcBindingInqAuthInfoExW function

## Description

The
**RpcBindingInqAuthInfoEx** function returns authentication, authorization, and security quality-of-service information from a binding handle.

## Parameters

### `Binding`

Server binding handle from which authentication and authorization information is returned.

### `ServerPrincName`

Returns a pointer to a pointer to the expected principal name of the server referenced in *Binding*. The content of the returned name and its syntax are defined by the authentication service in use.

Specify a null value to prevent
**RpcBindingInqAuthInfoEx** from returning the *ServerPrincName* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

### `AuthnLevel`

Returns a pointer set to the level of authentication used for remote procedure calls made using *Binding*. For a list of the RPC-supported authentication levels, see
[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants). Specify a null value to prevent the function from returning the *AuthnLevel* parameter.

The level returned in the *AuthnLevel* parameter may be different from the level specified when the client called the
[RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa) function. This discrepancy happens when the RPC run-time library does not support the authentication level specified by the client and automatically upgrades to the next higher authentication level.

### `AuthnSvc`

Returns a pointer set to the authentication service specified for remote procedure calls made using *Binding*. For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

Specify a null value to prevent
**RpcBindingInqAuthInfoEx** from returning the *AuthnSvc* parameter.

### `AuthIdentity`

Returns a pointer to a handle to the data structure that contains the client's authentication and authorization credentials specified for remote procedure calls made using *Binding*.

Specify a null value to prevent
**RpcBindingInqAuthInfoEx** from returning the *AuthIdentity* parameter.

### `AuthzSvc`

Returns a pointer set to the authorization service requested by the client application that made the remote procedure call on *Binding*. For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

Specify a null value to prevent
**RpcBindingInqAuthInfoEx** from returning the *AuthzSvc* parameter.

### `RpcQosVersion`

Passes value of current version (needed for forward compatibility if extensions are made to this function). Always set this parameter to RPC_C_SECURITY_QOS_VERSION.

### `SecurityQOS`

Returns pointer to the
[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos) structure, which defines quality-of-service settings.

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
**RpcBindingInqAuthInfoEx** function to view the authentication and authorization information associated with a server binding handle. This function provides the ability to inquire about the security quality of service on the binding handle. It is otherwise identical to
[RpcBindingInqAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfo).

The RPC run-time library allocates memory for the returned *ServerPrincName* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function for that returned argument string.

> [!NOTE]
> The rpcdce.h header defines RpcBindingInqAuthInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos)

[RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)