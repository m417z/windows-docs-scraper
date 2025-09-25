# FlatSB_SetScrollRange function

## Description

Sets the scroll range of a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Sets the scroll range of the horizontal scroll bar. |
| **SB_VERT** | Sets the scroll range of the vertical scroll bar. |

### `min`

Type: **int**

The new minimum scroll range value.

### `max`

Type: **int**

The new maximum scroll range value.

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be redrawn immediately to reflect the change. If this parameter is **TRUE**, the scroll bar is redrawn; if it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **int**

Returns nonzero if successful, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.