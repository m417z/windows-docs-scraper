# FlatSB_GetScrollInfo function

## Description

Gets the information for a flat scroll bar. If flat scroll bars are not initialized for the window, this function calls the standard [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that contains the flat scroll bar. This window handle must have been passed previously in a call to [InitializeFlatSB](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initializeflatsb).

### `code`

Type: **int**

A parameter that specifies the scroll bar type. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **SB_HORZ** | Retrieves the information for the horizontal scroll bar. |
| **SB_VERT** | Retrieves the information for the vertical scroll bar. |

### `unnamedParam3`

Type: **LPSCROLLINFO**

A pointer to a [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure that will receive the information for the specified scroll bar. The **cbSize** and **fMask** members of the structure must be filled out prior to calling **FlatSB_GetScrollInfo**. The **fMask** member specifies which properties should be retrieved and can be any combination of the following values:

| Value | Meaning |
| --- | --- |
| **SIF_PAGE** | Retrieves the page information for the flat scroll bar. This will be placed in the **nPage** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. |
| **SIF_POS** | Retrieves the position information for the flat scroll bar. This will be placed in the **nPos** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. |
| **SIF_RANGE** | Retrieves the range information for the flat scroll bar. This will be placed in the **nMin** and **nMax** members of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. |
| **SIF_ALL** | A combination of SIF_PAGE, SIF_POS, and SIF_RANGE. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

**Note** Flat scroll bar functions are implemented in Comctl32.dll versions 4.71 through 5.82. Comctl32.dll versions 6.00 and higher do not support flat scroll bars.