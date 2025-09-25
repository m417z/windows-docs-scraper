# FlatSB_GetScrollPos function

## Description

Gets the thumb position in a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The parameter that specifies the scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Retrieves the thumb position of the horizontal scroll bar. |
| **SB_VERT** | Retrieves the thumb position of the vertical scroll bar. |

## Return value

Type: **int**

Returns the current thumb position of the specified flat scroll bar.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.