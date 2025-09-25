# FlatSB_GetScrollPropPtr function

## Description

Gets the properties for a flat scroll bar. This function can also be used to determine if [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb) has been called for this window.

**Note** This is identical to [FlatSB_GetScrollProp](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-flatsb_getscrollprop).

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `propIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The parameter that determines what
*pValue* represents and which property is being retrieved. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WSB_PROP_CXHSCROLL** | *pValue* is a pointer to an INT value that receives the width, in pixels, of the direction buttons in a horizontal scroll bar. |
| **WSB_PROP_CXHTHUMB** | *pValue* is a pointer to an INT value that receives the width, in pixels, of the thumb in a horizontal scroll bar. |
| **WSB_PROP_CXVSCROLL** | *pValue* a pointer to an INT value that receives the width, in pixels, of a vertical scroll bar. |
| **WSB_PROP_CYHSCROLL** | *pValue* is a pointer to an INT value that receives the height, in pixels, of a horizontal scroll bar. |
| **WSB_PROP_CYVSCROLL** | *pValue* is a pointer to an INT value that receives the height, in pixels, of the direction buttons in a vertical scroll bar. |
| **WSB_PROP_CYVTHUMB** | *pValue* is a pointer to an INT value that receives the height, in pixels, of the thumb in a vertical scroll bar. |
| **WSB_PROP_HBKGCOLOR** | *pValue* is a pointer to a **COLORREF** value that receives the background color in a horizontal scroll bar. |
| **WSB_PROP_HSTYLE** | *pValue* is a pointer to an INT value that receives one of the following visual effects for the horizontal scroll bar. <br><br>FSB_ENCARTA_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar is displayed in 3-D.<br><br>FSB_FLAT_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar is displayed in inverted colors.<br><br>FSB_REGULAR_MODE<br><br>A normal, nonflat scroll bar is displayed. No special visual effects are applied. |
| **WSB_PROP_PALETTE** | *pValue* is a pointer to an **HPALETTE** value that receives the palette that a scroll bar uses when drawing. |
| **WSB_PROP_VBKGCOLOR** | *pValue* is a pointer to a **COLORREF** value that receives the background color in a vertical scroll bar. |
| **WSB_PROP_VSTYLE** | *pValue* is a pointer to an INT value that receives one of the following visual effects for the vertical scroll bar. <br><br>FSB_ENCARTA_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar is displayed in 3-D.<br><br>FSB_FLAT_MODE<br><br>A standard flat scroll bar is displayed. When the mouse moves over a direction button or the thumb, that portion of the scroll bar is displayed in inverted colors.<br><br>FSB_REGULAR_MODE<br><br>A normal, nonflat scroll bar is displayed. No special visual effects are applied. |
| **WSB_PROP_WINSTYLE** | *pValue* is a pointer to an INT value that receives the [WS_HSCROLL](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) and [WS_VSCROLL](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style bits contained by the current window. |

### `unnamedParam3`

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an **int** that receives the requested data. This parameter depends on the flag passed in
*index*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise. If
*index* is WSB_PROP_HSTYLE, the return is nonzero if [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb) has been called for this window, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.