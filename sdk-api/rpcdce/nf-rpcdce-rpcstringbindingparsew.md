# RpcStringBindingParseW function

## Description

The
**RpcStringBindingParse** function returns the object UUID part and the address parts of a string binding as separate strings. An application calls
**RpcStringBindingParse** to parse a string representation of a binding handle into its component fields. The
**RpcStringBindingParse** function returns the object UUID part and the address parts of a string binding as separate strings.

## Parameters

### `StringBinding`

Pointer to a **null**-terminated string representation of a binding.

### `ObjUuid`

Returns a pointer to a pointer to a **null**-terminated string representation of an object
[UUID](https://msdn.microsoft.com/).

Specify a **NULL** value to prevent
**RpcStringBindingParse** from returning the *ObjectUuid* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree).

### `Protseq`

Returns a pointer to a pointer to a **null**-terminated string representation of a protocol sequence. For a list of Microsoft RPC supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding).

Specify a **NULL** value to prevent
**RpcStringBindingParse** from returning the *ProtSeq* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree).

### `NetworkAddr`

Returns a pointer to a pointer to a **null**-terminated string representation of a network address. Specify a **NULL** value to prevent
**RpcStringBindingParse** from returning the *NetworkAddr* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree).

### `Endpoint`

Returns a pointer to a pointer to a **null**-terminated string representation of an endpoint. Specify a **NULL** value to prevent
**RpcStringBindingParse** from returning the *EndPoint* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree).

### `NetworkOptions`

Returns a pointer to a pointer to a **null**-terminated string representation of network options.

Specify a **NULL** value to prevent
**RpcStringBindingParse** from returning the *NetworkOptions* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_STRING_BINDING** | The string binding is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**RpcStringBindingParse** routine to parse a string representation of a binding handle into its component fields.

The RPC run-time library allocates memory for each component string returned. The application is responsible for calling
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) once for each returned string to deallocate the memory for that string.

If any field of the *StringBinding* parameter is empty,
**RpcStringBindingParse** returns an empty string (\0) in the corresponding output parameter.

**Note** To query a client's address, an application starts by calling the RpcBindingServerFromClient function to obtain a partially bound server binding handle. The server binding handle can be used to obtain a string binding by invoking RpcBindingToStringBinding. The server can then call RpcStringBindingParse to extract the client's network address from the string binding.

> [!NOTE]
> The rpcdce.h header defines RpcStringBindingParse as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcStringBindingCompose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingcompose)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)