# FlatSB_SetScrollInfo function

## Description

Sets the information for a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

The scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Sets the information for the horizontal scroll bar. |
| **SB_VERT** | Sets the information for the vertical scroll bar. |

### `psi`

Type: **LPSCROLLINFO**

A pointer to a [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure that contains the new information for the specified scroll bar. The **cbSize** and
**fMask** members of the structure must be filled in prior to calling **FlatSB_SetScrollInfo**. The **fMask** member specifies which members of the structure contain valid information and can be any combination of the following values:

| Value | Meaning |
| --- | --- |
| **SIF_DISABLENOSCROLL** | Disables the scroll bar if the new information would cause the scroll bar to be removed. |
| **SIF_PAGE** | Sets the page information for the flat scroll bar. The **nPage** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure must contain the new page value. |
| **SIF_POS** | Sets the position information for the flat scroll bar. The **nPos** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure must contain the new position value. |
| **SIF_RANGE** | Sets the range information for the flat scroll bar. The **nMin** and **nMax** members of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure must contain the new range values. |
| **SIF_ALL** | A combination of SIF_PAGE, SIF_POS, and SIF_RANGE. |

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be redrawn immediately to reflect the change. If this parameter is **TRUE**, the scroll bar is redrawn; if it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **int**

Returns the current scroll position. If the call to **FlatSB_SetScrollInfo** changes the scroll position, then the previous position is returned.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.