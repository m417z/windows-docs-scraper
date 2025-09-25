# GetScrollInfo function

## Description

The **GetScrollInfo** function retrieves the parameters of a scroll bar, including the minimum and maximum scrolling positions, the page size, and the position of the scroll box (thumb).

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*fnBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the type of scroll bar for which to retrieve parameters. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Retrieves the parameters for a scroll bar control. The *hwnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Retrieves the parameters for the window's standard horizontal scroll bar. |
| **SB_VERT** | Retrieves the parameters for the window's standard vertical scroll bar. |

### `lpsi` [in, out]

Type: **LPSCROLLINFO**

Pointer to a [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. Before calling **GetScrollInfo**, set the
**cbSize** member to
**sizeof**(**SCROLLINFO**), and set the
**fMask** member to specify the scroll bar parameters to retrieve. Before returning, the function copies the specified parameters to the appropriate members of the structure.

The
**fMask** member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SIF_PAGE** | Copies the scroll page to the **nPage** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |
| **SIF_POS** | Copies the scroll position to the **nPos** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |
| **SIF_RANGE** | Copies the scroll range to the **nMin** and **nMax** members of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |
| **SIF_TRACKPOS** | Copies the current scroll box tracking position to the **nTrackPos** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure pointed to by *lpsi*. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function retrieved any values, the return value is nonzero.

If the function does not retrieve any values, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetScrollInfo** function enables applications to use 32-bit scroll positions. Although the messages that indicate scroll bar position, [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll), provide only 16 bits of position data, the functions [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) and **GetScrollInfo** provide 32 bits of scroll bar position data. Thus, an application can call **GetScrollInfo** while processing either the **WM_HSCROLL** or **WM_VSCROLL** messages to obtain 32-bit scroll bar position data.

To get the 32-bit position of the scroll box (thumb) during a SB_THUMBTRACK request code in a [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) or [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll) message, call **GetScrollInfo** with the SIF_TRACKPOS value in the
**fMask** member of the [SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo) structure. The function returns the tracking position of the scroll box in the
**nTrackPos** member of the **SCROLLINFO** structure. This allows you to get the position of the scroll box as the user moves it. The following sample code illustrates the technique.

```
SCROLLINFO si;
case WM_HSCROLL:
    switch(LOWORD(wparam)) {
        case SB_THUMBTRACK:
          // Initialize SCROLLINFO structure

            ZeroMemory(&si, sizeof(si));
            si.cbSize = sizeof(si);
            si.fMask = SIF_TRACKPOS;

          // Call GetScrollInfo to get current tracking
          //    position in si.nTrackPos

            if (!GetScrollInfo(hwnd, SB_HORZ, &si) )
                return 1; // GetScrollInfo failed
            break;
        .
        .
        .
    }
```

If the *fnBar* parameter is SB_CTL and the window specified by the *hwnd* parameter is not a system scroll bar control, the system sends the [SBM_GETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-getscrollinfo) message to the window to obtain scroll bar information. This allows **GetScrollInfo** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_GETSCROLLINFO** message, the **GetScrollInfo** function fails.

## See also

**Reference**

[SCROLLINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollinfo)

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)

[WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll)

[WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll)