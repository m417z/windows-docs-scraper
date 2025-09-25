# RpcMgmtInqServerPrincNameW function

## Description

The
**RpcMgmtInqServerPrincName** function returns a server's principal name.

## Parameters

### `Binding`

To receive the principal name for a server, specify a server binding handle for that server. To receive the principal name for your own (local) application, specify a value of **NULL**.

### `AuthnSvc`

Authentication service for which a principal name is returned. Valid values are the constant for any valid security provider.

### `ServerPrincName`

Returns a principal name that is registered for the authentication service in *AuthnSvc* by the server referenced in *Binding*. If multiple names are registered, only one name is returned.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcMgmtInqServerPrincName** function to obtain the principal name of a server that is registered for a specified authentication service.

The RPC run-time library allocates memory for the string returned in *ServerPrincName*. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function to release the memory used by this function.

The server must be listening for remote procedure calls for this function to succeed. If the server is not listening, the function fails.

> [!NOTE]
> The rpcdce.h header defines RpcMgmtInqServerPrincName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)