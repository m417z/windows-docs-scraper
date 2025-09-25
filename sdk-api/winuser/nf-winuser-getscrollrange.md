# GetScrollRange function

## Description

The **GetScrollRange** function retrieves the current minimum and maximum scroll box (thumb) positions for the specified scroll bar.

**Note** The **GetScrollRange** function is provided for compatibility only. New applications should use the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*nBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the scroll bar from which the positions are retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Retrieves the positions of a scroll bar control. The *hWnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Retrieves the positions of the window's standard horizontal scroll bar. |
| **SB_VERT** | Retrieves the positions of the window's standard vertical scroll bar. |

### `lpMinPos` [out]

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the integer variable that receives the minimum position.

### `lpMaxPos` [out]

Type: **[LPINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the integer variable that receives the maximum position.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified window does not have standard scroll bars or is not a scroll bar control, the **GetScrollRange** function copies zero to the
*lpMinPos* and
*lpMaxPos* parameters.

The default range for a standard scroll bar is 0 through 100. The default range for a scroll bar control is empty (both values are zero).

The messages that indicate scroll bar position, [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll), are limited to 16 bits of position data. However, because [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo), [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos), [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange), [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo), [GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos), and **GetScrollRange** support 32-bit scroll bar position data, there is a way to circumvent the 16-bit barrier of the **WM_HSCROLL** and **WM_VSCROLL** messages. See the **GetScrollInfo** function for a description of the technique.

If the *nBar* parameter is SB_CTL and the window specified by the *hWnd* parameter is not a system scroll bar control, the system sends the [SBM_GETRANGE](https://learn.microsoft.com/windows/desktop/Controls/sbm-getrange) message to the window to obtain scroll bar information. This allows **GetScrollRange** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_GETRANGE** message, the **GetScrollRange** function fails.

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

[GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos)

**Reference**

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)

[SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos)

[SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange)

[WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll)

[WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll)