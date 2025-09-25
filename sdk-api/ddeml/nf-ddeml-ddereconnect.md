# DdeReconnect function

## Description

Enables a client [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) (DDEML) application to attempt to reestablish a conversation with a service that has terminated a conversation with the client. When the conversation is reestablished, the Dynamic Data Exchange Management Library (DDEML) attempts to reestablish any preexisting advise loops.

## Parameters

### `hConv` [in]

Type: **HCONV**

A handle to the conversation to be reestablished. A client must have obtained the conversation handle by a previous call to the [DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect) function or from an [XTYP_DISCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-disconnect) transaction.

## Return value

Type: **HCONV**

If the function succeeds, the return value is the handle to the reestablished conversation.

If the function fails, the return value is 0L.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## See also

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**