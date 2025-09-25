# RpcStringBindingCompose function

## Description

The
**RpcStringBindingCompose** function creates a string binding handle.

## Parameters

### `ObjUuid`

Pointer to a **null**-terminated string representation of an object
[UUID](https://msdn.microsoft.com/). For example, the string 6B29FC40-CA47-1067-B31D-00DD010662DA represents a valid UUID.

### `ProtSeq`

Pointer to a **null**-terminated string representation of a protocol sequence. See Note.

### `NetworkAddr`

Pointer to a **null**-terminated string representation of a network address. The network-address format is associated with the protocol sequence. See Note.

### `Endpoint`

Pointer to a **null**-terminated string representation of an endpoint. The endpoint format and content are associated with the protocol sequence. For example, the endpoint associated with the protocol sequence **ncacn_np** is a pipe name in the format \pipe\pipename. See Note.

### `Options`

Pointer to a **null**-terminated string representation of network options. The option string is associated with the protocol sequence. See Note.

### `StringBinding`

Returns a pointer to a pointer to a **null**-terminated string representation of a binding handle.

Specify a **NULL** value to prevent
**RpcStringBindingCompose** from returning the *StringBinding* parameter. In this case, the application does not call
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree). See Note.

**Note** For more information, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_STRING_UUID** | The string representation of the UUID is not valid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls
**RpcStringBindingCompose** routine to combine an object UUID, a protocol sequence, a network address, an endpoint and other network options into a string representation of a binding handle.

The RPC run-time library allocates memory for the string returned in the *StringBinding* parameter. The application is responsible for calling
[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree) to deallocate that memory.

Specify a **null** parameter value or provide an empty string (\0) for each input string that has no data.

Literal backslash characters within C-language strings must be quoted. The actual C string for the server name for the **ncacn_np** protocol sequence appears as \\\\servername, and the actual C string for a pipe name appears as \\pipe\\pipename.

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingToStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingtostringbinding)

[RpcStringBindingParse](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringbindingparse)

[RpcStringFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcstringfree)