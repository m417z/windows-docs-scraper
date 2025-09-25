# RPC_EE_INFO_PARAM structure

## Description

The
**RPC_EE_INFO_PARAM** structure is used to store extended error information.

## Members

### `ParameterType`

Type of parameter being provided as extended error information. This value determines which union member(s) is used. Valid values are the following:

* **eeptAnsiString** to specify an ANSI string, indicating the value is provided in **AnsiString**.
* **eeptUnicodeString** to specify a Unicode string, indicating the value is provided in **UnicodeString**.
* **eeptLongVal** to specify a LONG value, indicating the value is provided in **LVal**.
* **eeptShortVal** to specify a SHORT value, indicating the values is provided in **SVal**.
* **eeptPointerVal** to specify a pointer value, indicating the values is provided in **PVal**.
* **eeptBinary** is used by the RPC Runtime and should not be used or specified by applications.
* **eeptNone** indicates the parameter contained either a Unicode or ANSI string, but was truncated due to lack of memory or network fragment length limitations.

### `u`

### `u.AnsiString`

ANSI string representing the extended error information.

### `u.UnicodeString`

Unicode string representing the extended error information.

### `u.LVal`

Long value representing the extended error information.

### `u.SVal`

Short value representing the extended error information.

### `u.PVal`

ULONGLONG value representing the extended error information.

### `u.BVal`

Reserved.

## Remarks

The
**RPC_EE_INFO_PARAM** structure is used in conjunction with the **RpcError*** functions to investigate and create extended RPC error information.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

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

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)