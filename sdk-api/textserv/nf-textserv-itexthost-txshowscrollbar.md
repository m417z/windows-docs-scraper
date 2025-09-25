# ITextHost::TxShowScrollBar

## Description

Shows or hides the scroll bar in the text host window.

## Parameters

### `fnBar` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the scroll bar(s) to be shown or hidden. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| SB_BOTH | Shows or hides a window's standard horizontal and vertical scroll bars. |
| SB_HORZ | Shows or hides a window's standard horizontal scroll bars. |
| SB_VERT | Shows or hides a window's standard vertical scroll bar. |

### `fShow` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag. If **TRUE**, the scroll bars indicated by *fnBar* is visible. If **FALSE**, the scroll bar is hidden.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the method succeeds.

Return **FALSE** if the method fails.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)