# DdeDisconnect function

## Description

Terminates a conversation started by either the [DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect) or [DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist) function and invalidates the specified conversation handle.

## Parameters

### `hConv` [in]

Type: **HCONV**

A handle to the active conversation to be terminated.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

Any incomplete transactions started before calling **DdeDisconnect** are immediately abandoned. The [XTYP_DISCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-disconnect) transaction is sent to the Dynamic Data Exchange (DDE) callback function of the partner in the conversation. Generally, only client applications must terminate conversations.

## See also

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeDisconnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnectlist)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**

[XTYP_DISCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-disconnect)