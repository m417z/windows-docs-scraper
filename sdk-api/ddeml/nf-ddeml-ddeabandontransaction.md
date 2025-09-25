# DdeAbandonTransaction function

## Description

Abandons the specified asynchronous transaction and releases all resources associated with the transaction.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hConv` [in]

Type: **HCONV**

A handle to the conversation in which the transaction was initiated. If this parameter is 0L, all transactions are abandoned (that is, the
*idTransaction* parameter is ignored).

### `idTransaction` [in]

Type: **DWORD**

The identifier of the transaction to be abandoned. If this parameter is 0L, all active transactions in the specified conversation are abandoned.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

Only a Dynamic Data Exchange (DDE) client application should call **DdeAbandonTransaction**. If the server application responds to the transaction after the client has called **DdeAbandonTransaction**, the system discards the transaction results. This function has no effect on synchronous transactions.

## See also

**Conceptual**

[DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**