# RpcBindingToStringBindingA function

## Description

The
**RpcBindingToStringBinding** function returns a string representation of a binding handle.

## Parameters

### `Binding`

Client or server binding handle to convert to a string representation of a binding handle.

### `StringBinding`

Returns a pointer to a pointer to the string representation of the binding handle specified in the *Binding* parameter.

Specify a null value to prevent
**RpcBindingToStringBinding** from returning the *StringBinding* parameter. In this case, the application does not call the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcBindingToStringBinding** function converts a client or server binding handle to its string representation.

The RPC run-time library allocates memory for the string returned in the *StringBinding* parameter. The application is responsible for calling the
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) function to deallocate that memory.

If the binding handle in the *Binding* parameter contained a nil object
[UUID](https://msdn.microsoft.com/), the object UUID field is not included in the returned string.

To parse the returned *StringBinding* parameter, call the
[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse) function.

**Note** To query a client's address, an application starts by calling the RpcBindingServerFromClient function to obtain a partially bound server binding handle. The server binding handle can be used to obtain a string binding by invoking RpcBindingToStringBinding. The server can then call RpcStringBindingParse to extract the client's network address from the string binding.

> [!NOTE]
> The rpcdce.h header defines RpcBindingToStringBinding as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)