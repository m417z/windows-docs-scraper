# RpcBindingFromStringBindingW function

## Description

The
**RpcBindingFromStringBinding** function returns a binding handle from a string representation of a binding handle.

## Parameters

### `StringBinding`

Pointer to a string representation of a binding handle.

### `Binding`

Returns a pointer to the server binding handle.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_STRING_BINDING** | The string binding is not valid. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | Protocol sequence not supported on this host. |
| **RPC_S_INVALID_RPC_PROTSEQ** | The protocol sequence is not valid. |
| **RPC_S_INVALID_ENDPOINT_FORMAT** | The endpoint format is not valid. |
| **RPC_S_STRING_TOO_LONG** | String too long. |
| **RPC_S_INVALID_NET_ADDR** | The network address is not valid. |
| **RPC_S_INVALID_ARG** | The argument was not valid. |
| **RPC_S_INVALID_NAF_ID** | The network address family identifier is not valid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcBindingFromStringBinding** function creates a server binding handle from a string representation of a binding handle. The *StringBinding* parameter does not have to contain an object
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid). In this case, the returned binding contains a nil UUID. If the provided *StringBinding* parameter does not contain an endpoint field, the returned *Binding* parameter is a partially-bound binding handle. If the provided *StringBinding* parameter contains an endpoint field, the endpoint is considered to be a well-known endpoint. If the provided *StringBinding* parameter does not contain a host address field, the returned *Binding* parameter references the local host.

An application creates a string binding by calling the
[RpcStringBindingCompose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingcompose) function or by providing a character-string constant. The creation of a string binding by this method does not involve contact with the server. Success or failure of the API will not indicate server availability.

When an application is finished using the *Binding* parameter, the application should call the
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) function to release the memory used by the binding handle.

> [!NOTE]
> The rpcdce.h header defines RpcBindingFromStringBinding as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingCopy](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcopy)

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcStringBindingCompose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingcompose)