# DdePostAdvise function

## Description

Causes the system to send an [XTYP_ADVREQ](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advreq) transaction to the calling (server) application's Dynamic Data Exchange (DDE) callback function for each client with an active advise loop on the specified topic and item. A server application should call this function whenever the data associated with the topic name or item name pair changes.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hszTopic` [in]

Type: **HSZ**

A handle to a string that specifies the topic name. To send notifications for all topics with active advise loops, an application can set this parameter to 0L.

### `hszItem` [in]

Type: **HSZ**

A handle to a string that specifies the item name. To send notifications for all items with active advise loops, an application can set this parameter to 0L.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

A server that has nonenumerable topics or items should set the
*hszTopic* and
*hszItem* parameters to **NULL** so that the system generates transactions for all active advise loops. The server's DDE callback function returns **NULL** for any advise loops that must not be updated.

If a server calls **DdePostAdvise** with a topic, item, and format name set that includes the set currently being handled in an [XTYP_ADVREQ](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advreq) callback, a stack overflow can result.

## See also

**Conceptual**

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**

[XTYP_ADVREQ](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advreq)