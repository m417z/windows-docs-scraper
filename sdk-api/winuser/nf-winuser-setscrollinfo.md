# SetScrollInfo function

## Description

The **SetScrollInfo** function sets the parameters of a scroll bar, including the minimum and maximum scrolling positions, the page size, and the position of the scroll box (thumb). The function also redraws the scroll bar, if requested.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*fnBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the type of scroll bar for which to set parameters. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Sets the parameters of a scroll bar control. The *hwnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Sets the parameters of the window's standard horizontal scroll bar. |
| **SB_VERT** | Sets the parameters of the window's standard vertical scroll bar. |

### `lpsi` [in]

Type: **LPCSCROLLINFO**

Pointer to a [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. Before calling **SetScrollInfo**, set the
**cbSize** member of the structure to
**sizeof**(**SCROLLINFO**), set the
**fMask** member to indicate the parameters to set, and specify the new parameter values in the appropriate members.

The
**fMask** member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SIF_DISABLENOSCROLL** | Disables the scroll bar instead of removing it, if the scroll bar's new parameters make the scroll bar unnecessary. |
| **SIF_PAGE** | Sets the scroll page to the value specified in the **nPage** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |
| **SIF_POS** | Sets the scroll position to the value specified in the **nPos** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |
| **SIF_RANGE** | Sets the scroll range to the value specified in the **nMin** and **nMax** members of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |

### `redraw` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar is redrawn to reflect the changes to the scroll bar. If this parameter is **TRUE**, the scroll bar is redrawn, otherwise, it is not redrawn.

## Return value

Type: **int**

The return value is the current position of the scroll box.

## Remarks

The **SetScrollInfo** function performs range checking on the values specified by the
**nPage** and
**nPos** members of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. The
**nPage** member must specify a value from 0 to
**nMax** -
**nMin** +1. The
**nPos** member must specify a value between
**nMin** and
**nMax** -
**max**(
**nPage**– 1, 0). If either value is beyond its range, the function sets it to a value that is just within the range.

If the *fnBar* parameter is SB_CTL and the window specified by the *hwnd* parameter is not a system scroll bar control, the system sends the [SBM_SETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-setscrollinfo) message to the window to set scroll bar information (The system can optimize the message to [SBM_SETPOS](https://learn.microsoft.com/windows/desktop/Controls/sbm-setpos) or [SBM_SETRANGE](https://learn.microsoft.com/windows/desktop/Controls/sbm-setrange) if the request is solely for the position or range). This allows **SetScrollInfo** to operate on a custom control that mimics a scroll bar. If the window does not handle **SBM_SETSCROLLINFO** (or the optimized **SBM_SETPOS** message or **SBM_SETRANGE** message), then the **SetScrollInfo** function fails.

For an example, see [Scrolling Text with the WM_PAINT Message](https://learn.microsoft.com/windows/desktop/Controls/using-scroll-bars).

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

**Reference**

[SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo)