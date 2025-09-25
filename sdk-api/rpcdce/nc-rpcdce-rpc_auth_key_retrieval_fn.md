# RPC_AUTH_KEY_RETRIEVAL_FN callback function

## Description

The
*RPC_AUTH_KEY_RETRIEVAL_FN* function is a prototype for a function that specifies the address of a server-application-provided routine returning encryption keys.

## Parameters

### `Arg`

Pointer to a user-defined argument to the user-supplied encryption key acquisition function. The RPC run-time library uses the *Arg* parameter supplied to
[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo).

### `ServerPrincName`

Pointer to the principal name to use for the server when authenticating remote procedure calls. The RPC run-time library uses the *ServerPrincName* parameter supplied to
[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo).

### `KeyVer`

Value that the RPC run-time library automatically provides for the key-version parameter. When the value is zero, the acquisition function must return the most recent key available.

#### - **Key

Pointer to a pointer to the authentication key returned by the user-supplied function.

### `Status`

Pointer to the status returned by the acquisition function when it is called by the RPC run-time library to authenticate the client RPC request. If the status is other than RPC_S_OK, the request fails and the run-time library returns the error status to the client application.

### `Key`

Pointer to a pointer to the authentication key returned by the user-supplied function.

## Remarks

An authorization key–retrieval function specifies the address of a server-application-provided routine returning encryption keys.

## See also

[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo)