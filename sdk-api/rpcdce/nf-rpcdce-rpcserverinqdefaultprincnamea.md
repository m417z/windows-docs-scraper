# RpcServerInqDefaultPrincNameA function

## Description

The
**RpcServerInqDefaultPrincName** function obtains the default principal name for a given authentication service.

## Parameters

### `AuthnSvc`

Authentication service to use when the server receives a request for a remote procedure call.

### `PrincName`

Upon success, contains the default principal name for the given authentication service as specified by the *AuthnSvc* parameter. The authentication service in use defines the content of the name and its syntax. This principal name must be used as the *ServerPrincName* parameter of the [RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo) function. If the function succeeds, *PrincName* must be freed using the [RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function. If the function fails, the contents of *PrincName* is undefined and the caller has no obligation to free it.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_MEMORY** | There is insufficient memory to complete the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

This function is the recommended way to obtain the server principal name to be passed to the [RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo) function. While composing the server principal name is possible without using this function, calling the function is easier and more portable across operating system versions.

> [!NOTE]
> The rpcdce.h header defines RpcServerInqDefaultPrincName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo)

[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo)