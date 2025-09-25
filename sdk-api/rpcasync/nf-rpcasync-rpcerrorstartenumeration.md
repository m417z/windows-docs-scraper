# RpcErrorStartEnumeration function

## Description

The
**RpcErrorStartEnumeration** function begins enumeration of extended error information.

## Parameters

### `EnumHandle`

Pointer to the enumeration handle, in the form of an
[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle) structure. The structure must be allocated by the caller, and cannot be freed until the operation is complete. All members are ignored on input.

## Return value

Successful completion returns RPC_S_OK.

Returns RPC_S_ENTRY_NOT_FOUND if no extended error information is on the thread. If an enumeration is in progress, starting a second enumeration starts from the beginning.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The RpcErrorStartEnumeration function call should be made immediately after the call that returned the error. Otherwise, extended error information may be overwritten by subsequent calls. Enumeration handles must be freed with the RpcErrorEndEnumeration function.

Once
**RpcErrorStartEnumeration** is called, it is safe to use the enumeration handle from a different thread. The
**RpcErrorStartEnumeration** function takes a snapshot of the extended error information, and the returning enumeration handle operates on the snapshot. However, enumeration functions are not synchronized between threads by RPC, and so the caller is responsible for doing so. Subsequent calls to
**RpcErrorStartEnumeration** begins a new enumeration, and does not create a second enumeration for the same extended error information.

The RpcErrorStartEnumeration function may fail if there is not enough memory to begin the enumeration. The enumeration handle can be passed only to **RpcError*** functions, and cannot be used with other functions, such as **DuplicateHandle**.

Advancing the enumeration pointer on one enumeration has no effect on independently started enumerations.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info)

[RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord)

[RpcErrorClearInformation](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorclearinformation)

[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorGetNumberOfRecords](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnumberofrecords)

[RpcErrorLoadErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorloaderrorinfo)

[RpcErrorResetEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorresetenumeration)

[RpcErrorSaveErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorsaveerrorinfo)