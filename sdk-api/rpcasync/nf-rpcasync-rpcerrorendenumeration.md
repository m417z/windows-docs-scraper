# RpcErrorEndEnumeration function

## Description

The
**RpcErrorEndEnumeration** function ends enumeration of extended error information and frees all resources allocated by RPC for the enumeration.

## Parameters

### `EnumHandle`

Pointer to the enumeration handle.

## Return value

Successful completion returns RPC_S_OK. The
**RpcErrorEndEnumeration** function call cannot fail unless its parameters are invalid.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcErrorEndEnumeration** function zeros out the enumeration handle to prevent further usage. If the CopyStrings option was not used during a previous call to the
[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord) function, all non-empty **ComputerName** fields and **AnsiString** or **UnicodeString** values are invalid after this function is called.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)