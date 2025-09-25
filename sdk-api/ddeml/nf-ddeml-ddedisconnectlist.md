# DdeDisconnectList function

## Description

Destroys the specified conversation list and terminates all conversations associated with the list.

## Parameters

### `hConvList` [in]

Type: **HCONVLIST**

A handle to the conversation list. This handle must have been created by a previous call to the [DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

An application can use the [DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect) function to terminate individual conversations in the list.

## See also

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**