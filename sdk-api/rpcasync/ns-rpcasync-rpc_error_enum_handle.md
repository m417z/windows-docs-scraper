# RPC_ERROR_ENUM_HANDLE structure

## Description

The
**RPC_ERROR_ENUM_HANDLE** structure provides an enumeration handle used by **RpcError*** functions for processing extended error information. All members of the
**RPC_ERROR_ENUM_HANDLE** structure are used internally by the RPC Runtime, and should not be read or changed by applications. Applications should treat the
**RPC_ERROR_ENUM_HANDLE** as an opaque value used as a handle.

## Members

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param)

[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info)

[RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord)

[RpcErrorClearInformation](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorclearinformation)

[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorGetNumberOfRecords](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnumberofrecords)

[RpcErrorLoadErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorloaderrorinfo)

[RpcErrorResetEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorresetenumeration)

[RpcErrorSaveErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorsaveerrorinfo)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)