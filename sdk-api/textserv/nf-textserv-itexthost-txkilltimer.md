# ITextHost::TxKillTimer

## Description

Requests the text host to destroy the specified timer.

## Parameters

### `idTimer` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifier of the timer created by the [ITextHost::TxSetTimer](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsettimer) method.

## Remarks

This method may be called at any time, whether the control is active or inactive.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxSetTimer](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsettimer)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)