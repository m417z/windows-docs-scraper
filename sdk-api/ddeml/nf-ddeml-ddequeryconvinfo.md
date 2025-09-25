# DdeQueryConvInfo function

## Description

Retrieves information about a Dynamic Data Exchange (DDE) transaction and about the conversation in which the transaction takes place.

## Parameters

### `hConv` [in]

Type: **HCONV**

A handle to the conversation.

### `idTransaction` [in]

Type: **DWORD**

The transaction. For asynchronous transactions, this parameter should be a transaction identifier returned by the [DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction) function. For synchronous transactions, this parameter should be QID_SYNC.

### `pConvInfo` [in, out]

Type: **PCONVINFO**

A pointer to the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure that receives information about the transaction and conversation. The
*cb* member of the **CONVINFO** structure must specify the length of the buffer allocated for the structure.

## Return value

Type: **UINT**

If the function succeeds, the return value is the number of bytes copied into the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure.

If the function fails, the return value is **FALSE**.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

An application should not free a string handle referenced by the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure. If an application must use one of these string handles, it should call the [DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle) function to create a copy of the handle.

If the
*idTransaction* parameter is set to QID_SYNC, the
*hUser* member of the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure is associated with the conversation and can be used to hold data associated with the conversation. If
*idTransaction* is the identifier of an asynchronous transaction, the
*hUser* member is associated only with the current transaction and is valid only for the duration of the transaction.

## See also

[CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo)

**Conceptual**

[DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction)

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle)

[DdeQueryNextServer](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerynextserver)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**