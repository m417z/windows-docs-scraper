# FlatSB_ShowScrollBar function

## Description

Shows or hides a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [ShowScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showscrollbar) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_BOTH** | Shows or hides the horizontal and vertical scroll bars. |
| **SB_HORZ** | Shows or hides the horizontal scroll bar. |
| **SB_VERT** | Shows or hides the vertical scroll bar. |

### `unnamedParam3`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be shown or hidden. If this parameter is nonzero, the scroll bar will be shown; if it is zero, the scroll bar will be hidden.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.