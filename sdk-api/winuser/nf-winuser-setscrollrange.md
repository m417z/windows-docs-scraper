# SetScrollRange function

## Description

The **SetScrollRange** function sets the minimum and maximum scroll box positions for the specified scroll bar.

**Note** The **SetScrollRange** function is provided for backward compatibility. New applications should use the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*nBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the scroll bar to be set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Sets the range of a scroll bar control. The *hwnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Sets the range of a window's standard horizontal scroll bar. |
| **SB_VERT** | Sets the range of a window's standard vertical scroll bar. |

### `nMinPos` [in]

Type: **int**

Specifies the minimum scrolling position.

### `nMaxPos` [in]

Type: **int**

Specifies the maximum scrolling position.

### `bRedraw` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar should be redrawn to reflect the change. If this parameter is **TRUE**, the scroll bar is redrawn. If it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use **SetScrollRange** to hide the scroll bar by setting
*nMinPos* and
*nMaxPos* to the same value. An application should not call the **SetScrollRange** function to hide a scroll bar while processing a scroll bar message. New applications should use the [ShowScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showscrollbar) function to hide the scroll bar.

If the call to **SetScrollRange** immediately follows a call to the [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos) function, the
*bRedraw* parameter in **SetScrollPos** must be zero to prevent the scroll bar from being drawn twice.

The default range for a standard scroll bar is 0 through 100. The default range for a scroll bar control is empty (both the
*nMinPos* and
*nMaxPos* parameter values are zero). The difference between the values specified by the
*nMinPos* and
*nMaxPos* parameters must not be greater than the value of MAXLONG.

Because the messages that indicate scroll bar position,
[WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and
[WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll), are limited to 16 bits of position data, applications that rely solely on those messages for position data have a practical maximum value of 65,535 for the **SetScrollRange** function's
*nMaxPos* parameter.

However, because the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo), [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos), **SetScrollRange**, [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo), [GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos), and [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange) functions support 32-bit scroll bar position data, there is a way to circumvent the 16-bit barrier of the
[WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and
[WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll) messages. See **GetScrollInfo** for a description of the technique.

If the *nBar* parameter is SB_CTL and the window specified by the *hWnd* parameter is not a system scroll bar control, the system sends the [SBM_SETRANGE](https://learn.microsoft.com/windows/desktop/Controls/sbm-setrange) message to the window to set scroll bar information. This allows **SetScrollRange** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_SETRANGE** message, the **SetScrollRange** function fails.

#### Examples

For an example, see [Using the Owner-Display Clipboard Format](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

[GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos)

[GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange)

**Reference**

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)

[SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos)

[ShowScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showscrollbar)