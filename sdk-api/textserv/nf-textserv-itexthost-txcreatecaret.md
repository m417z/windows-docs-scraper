# ITextHost::TxCreateCaret

## Description

Creates a new shape for windowless rich edit control's caret.

## Parameters

### `hbmp` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the bitmap for the new caret shape.

If the windowless rich edit control has the [SES_LOGICALCARET](https://learn.microsoft.com/windows/desktop/Controls/em-seteditstyle) style, *hbmp* is a combination of the following values:

| Value | Meaning |
| --- | --- |
| **CARET_CUSTOM** | An adorned caret. This value is valid only if CARET_RTL is also specified. |
| **CARET_ITALIC** | An italicized caret. |
| **CARET_NONE** | A blinking vertical bar. |
| **CARET_NULL** | An empty bitmap (for non-degenerate text selection). |
| **CARET_ROTATE90** | A caret that is rotated clockwise by 90 degrees. |
| **CARET_RTL** | The caret moves right to left. |

### `xWidth` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Caret width, in logical units.

### `yHeight` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Caret height, in logical units.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the method succeeds.

Return **FALSE** if the method fails.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

**Conceptual**

[CreateCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcaret)

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Other Resources**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)