# RpcErrorResetEnumeration function

## Description

The
**RpcErrorResetEnumeration** function resets an enumeration cursor for any in-process enumeration, resetting the process such that a subsequent call to the
[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord) retrieves the first extended error information record.

## Parameters

### `EnumHandle`

Pointer to the enumeration handle.

## Return value

Successful completion returns RPC_S_OK. The
**RpcErrorResetEnumeration** function call cannot fail unless its parameters are invalid.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcErrorResetEnumeration** function call can reset an enumeration of extended error information even if the
[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord) function reaches the end of enumerations and returns RPC_S_SNTRY_NOT_FOUND.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)