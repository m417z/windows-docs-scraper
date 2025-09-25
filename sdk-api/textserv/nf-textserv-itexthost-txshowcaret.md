# ITextHost::TxShowCaret

## Description

Shows or hides the caret at the caret position in the text host window.

## Parameters

### `fShow` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag. If **TRUE**, the caret is visible. If **FALSE**, the caret is hidden.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the method succeeds.

Return **FALSE** if the method fails.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxCreateCaret](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txcreatecaret)

[TxSetCaretPos](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetcaretpos)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)