# FlatSB_GetScrollRange function

## Description

Gets the scroll range for a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Retrieves the scroll range of the horizontal scroll bar. |
| **SB_VERT** | Retrieves the scroll range of the vertical scroll bar. |

### `unnamedParam3`

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an INT value that receives the minimum scroll range value.

### `unnamedParam4`

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an INT value that receives the maximum scroll range value.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.