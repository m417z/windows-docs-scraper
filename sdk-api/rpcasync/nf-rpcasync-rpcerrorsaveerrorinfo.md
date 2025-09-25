# RpcErrorSaveErrorInfo function

## Description

The
**RpcErrorSaveErrorInfo** function returns all error information for an enumeration handle as a BLOB.

## Parameters

### `EnumHandle` [in]

Pointer to the enumeration handle.

### `ErrorBlob` [out]

Pointer to the BLOB containing the error information.

### `BlobSize` [out]

Size of *ErrorBlob*, in bytes.

## Return value

Successful completion returns RPC_S_OK. The
**RpcErrorSaveErrorInfo** function call may fail if not enough memory is available.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The BLOB is allocated on the system heap, and the caller is the owner of the buffer. The block allocated on the system heap may be larger than *BlobSize*, but only *BlobSize* is used. The
**RpcErrorSaveErrorInfo** function saves the entire chain of extended error information records associated with the enumeration handle, regardless of cursor position, and does not change the cursor position for the enumeration.

The BLOB may be saved and later retrieved using the
[RpcErrorLoadErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorloaderrorinfo) function.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorLoadErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorloaderrorinfo)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)