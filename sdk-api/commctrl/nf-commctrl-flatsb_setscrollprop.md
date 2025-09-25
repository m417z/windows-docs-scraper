# FlatSB_SetScrollProp function

## Description

Sets the properties for a flat scroll bar.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `index`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Determines what
*newValue* represents and which property is being set. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WSB_PROP_CXHSCROLL** | *newValue* is an INT_PTR value that represents the width, in pixels, of the direction buttons in a horizontal scroll bar. |
| **WSB_PROP_CXHTHUMB** | *newValue* is an INT_PTR value that represents the width, in pixels, of the thumb in a horizontal scroll bar. |
| **WSB_PROP_CXVSCROLL** | *newValue* is an INT_PTR value that represents the width, in pixels, of the vertical scroll bar. |
| **WSB_PROP_CYHSCROLL** | *newValue* is an INT_PTR value that represents the height, in pixels, of the horizontal scroll bar. |
| **WSB_PROP_CYVSCROLL** | *newValue* is an INT_PTR value that represents the height, in pixels, of the direction buttons in a vertical scroll bar. |
| **WSB_PROP_CYVTHUMB** | *newValue* is an INT_PTR value that represents the height, in pixels, of the thumb in a vertical scroll bar. |
| **WSB_PROP_HBKGCOLOR** | *newValue* is a **COLORREF** value that represents the background color in a horizontal scroll bar. |
| **WSB_PROP_HSTYLE** | *newValue* is one of the following values that changes the visual effects for the horizontal scroll bar. <br><br>FSB_ENCARTA_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar will be displayed in 3-D.<br><br>FSB_FLAT_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar will be displayed in inverted colors.<br><br>FSB_REGULAR_MODE<br><br>A normal, nonflat scroll bar is displayed. No special visual effects will be applied. |
| **WSB_PROP_PALETTE** | *newValue* is an **HPALETTE** value that represents the new palette that the scroll bar should use when drawing. |
| **WSB_PROP_VBKGCOLOR** | *newValue* is a **COLORREF** value that represents the background color in a vertical scroll bar. |
| **WSB_PROP_VSTYLE** | *newValue* is one of the following values that changes the visual effects for the vertical scroll bar: <br><br>FSB_ENCARTA_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar will be displayed in 3-D.<br><br>FSB_FLAT_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar will be displayed in inverted colors.<br><br>FSB_REGULAR_MODE<br><br>A normal, nonflat scroll bar is displayed. No special visual effects will be applied. |

### `newValue`

Type: **[INT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A new value to set. This parameter depends on the flag passed in
*index*.

### `unnamedParam4`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be redrawn immediately to reflect the change. If this parameter is **TRUE**, the scroll bar is redrawn; if it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.