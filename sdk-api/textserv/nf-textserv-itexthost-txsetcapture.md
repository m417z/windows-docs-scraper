# ITextHost::TxSetCapture

## Description

Sets the mouse capture in the text host's window.

## Parameters

### `fCapture` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether to set or release the mouse capture. If **TRUE**, the mouse capture is set. If **FALSE**, the mouse capture is released.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may do nothing.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)