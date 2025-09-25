# GetScrollPos function

## Description

The **GetScrollPos** function retrieves the current position of the scroll box (thumb) in the specified scroll bar. The current position is a relative value that depends on the current scrolling range. For example, if the scrolling range is 0 through 100 and the scroll box is in the middle of the bar, the current position is 50.

**Note** The **GetScrollPos** function is provided for backward compatibility. New applications should use the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*nBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the scroll bar to be examined. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Retrieves the position of the scroll box in a scroll bar control. The *hWnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Retrieves the position of the scroll box in a window's standard horizontal scroll bar. |
| **SB_VERT** | Retrieves the position of the scroll box in a window's standard vertical scroll bar. |

## Return value

Type: **int**

If the function succeeds, the return value is the current position of the scroll box.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetScrollPos** function enables applications to use 32-bit scroll positions. Although the messages that indicate scroll bar position, [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll), are limited to 16 bits of position data, the functions [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos), [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange), **GetScrollPos**, and [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange) support 32-bit scroll bar position data. Thus, an application can call **GetScrollPos** while processing either the **WM_HSCROLL** or **WM_VSCROLL** messages to obtain 32-bit scroll bar position data.

To get the 32-bit position of the scroll box (thumb) during a SB_THUMBTRACK request code in a [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) or [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll) message, use the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

If the *nBar* parameter is SB_CTL and the window specified by the *hWnd* parameter is not a system scroll bar control, the system sends the [SBM_GETPOS](https://learn.microsoft.com/windows/desktop/Controls/sbm-getpos) message to the window to obtain scroll bar information. This allows **GetScrollPos** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_GETPOS** message, the **GetScrollPos** function fails.

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

[GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange)

**Reference**

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)

[SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos)

[SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange)

[WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll)

[WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll)