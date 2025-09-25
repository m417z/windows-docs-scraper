# RpcErrorGetNumberOfRecords function

## Description

The
**RpcErrorGetNumberOfRecords** function returns the number of records in the extended error information.

## Parameters

### `EnumHandle` [in]

Pointer to the enumeration handle.

### `Records` [out]

Number of records for the extended error information.

## Return value

Successful completion returns RPC_S_OK. The **RpcErrorGetNumberOfRecords** function call cannot fail unless its parameters are invalid.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcErrorGetNumberOfRecords** function returns the total number of records in the extended error information, not the number of records from the current cursor location.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)