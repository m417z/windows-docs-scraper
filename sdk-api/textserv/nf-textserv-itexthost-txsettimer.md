# ITextHost::TxSetTimer

## Description

Requests the text host to create a timer with a specified time-out.

## Parameters

### `idTimer` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Timer identifier.

### `uTimeout` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Time-out in milliseconds.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the method succeeds.

Return **FALSE** if the method fails.

## Remarks

*idTimer* is used in [ITextHost::TxKillTimer](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txkilltimer).

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxKillTimer](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txkilltimer)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)