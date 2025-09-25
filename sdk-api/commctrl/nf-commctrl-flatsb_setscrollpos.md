# FlatSB_SetScrollPos function

## Description

Sets the current position of the thumb in a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Sets the thumb position of the horizontal scroll bar. |
| **SB_VERT** | Sets the thumb position of the vertical scroll bar. |

### `pos`

Type: **int**

The new thumb position.

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be redrawn immediately to reflect the change. If this parameter is **TRUE**, the scroll bar is redrawn; if it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **int**

Returns the previous position of the thumb in the specified flat scroll bar.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.