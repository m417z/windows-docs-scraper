# RpcErrorLoadErrorInfo function

## Description

The
**RpcErrorLoadErrorInfo** function converts a BLOB obtained by a call to
[RpcErrorSaveErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorsaveerrorinfo) into extended error information.

## Parameters

### `ErrorBlob` [in]

Pointer to the BLOB containing the error information.

### `BlobSize` [in]

Size of *ErrorBlob*, in bytes.

### `EnumHandle` [out]

Pointer to the enumeration handle associated with the extended error information.

## Return value

Successful completion returns RPC_S_OK. The **RpcErrorLoadInfo** function call can fail if not enough memory is available.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The BLOB pointed to in *ErrorBlob* remains the responsibility of the caller. The resulting enumeration is ready for enumeration. EnumHandle is subject to the same requirements of the *EnumHandle* parameter for
[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration). Once enumeration is completed, resources allocated by the enumeration should be freed using the
[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration) function.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration)

[RpcErrorSaveErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorsaveerrorinfo)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)