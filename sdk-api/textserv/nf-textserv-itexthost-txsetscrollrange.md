# ITextHost::TxSetScrollRange

## Description

Sets the minimum and maximum position values for the specified scroll bar in the text host window.

## Parameters

### `fnBar` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scroll bar flag. If this is SB_HORZ, horizontal scrolling is done. By default, vertical scrolling is done.

### `nMinPos` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum scrolling position.

### `nMaxPos` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum scrolling position.

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Redraw flag. If **TRUE**, the scroll bar is redrawn to reflect the changes. If **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the arrows are enabled or disabled as specified.

Return **FALSE** if the arrows are already in the requested state or an error occurs.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)