# ITextHost::TxSetScrollPos

## Description

Sets the position of the scroll box (thumb) in the specified scroll bar and, if requested, redraws the scroll bar to reflect the new position of the scroll box.

## Parameters

### `fnBar` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scroll bar flag. If this is SB_HORZ, horizontal scrolling is done. By default, vertical scrolling is done.

### `nPos` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New position in scroll box. This must be within the range of scroll bar values set by [ITextHost::TxSetScrollRange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetscrollrange).

### `fRedraw` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Redraw flag. If **TRUE**, the scroll bar is redrawn with the new position of the scroll box. If **FALSE**, the scroll bar is not redrawn.

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

[TxSetScrollRange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txsetscrollrange)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)