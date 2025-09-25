# SetScrollPos function

## Description

The **SetScrollPos** function sets the position of the scroll box (thumb) in the specified scroll bar and, if requested, redraws the scroll bar to reflect the new position of the scroll box.

**Note** The **SetScrollPos** function is provided for backward compatibility. New applications should use the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the *nBar* parameter.

### `nBar` [in]

Type: **int**

Specifies the scroll bar to be set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_CTL** | Sets the position of the scroll box in a scroll bar control. The *hwnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Sets the position of the scroll box in a window's standard horizontal scroll bar. |
| **SB_VERT** | Sets the position of the scroll box in a window's standard vertical scroll bar. |

### `nPos` [in]

Type: **int**

Specifies the new position of the scroll box. The position must be within the scrolling range. For more information about the scrolling range, see the [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange) function.

### `bRedraw` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar is redrawn to reflect the new scroll box position. If this parameter is **TRUE**, the scroll bar is redrawn. If it is **FALSE**, the scroll bar is not redrawn.

## Return value

Type: **int**

If the function succeeds, the return value is the previous position of the scroll box.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the scroll bar is redrawn by a subsequent call to another function, setting the *bRedraw* parameter to **FALSE** is useful.

Because the messages that indicate scroll bar position, [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll), are limited to 16 bits of position data, applications that rely solely on those messages for position data have a practical maximum value of 65,535 for the **SetScrollPos** function's *nPos* parameter.

However, because the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo), **SetScrollPos**, [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange), [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo), [GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos), and [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange) functions support 32-bit scroll bar position data, there is a way to circumvent the 16-bit barrier of the [WM_HSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-hscroll) and [WM_VSCROLL](https://learn.microsoft.com/windows/desktop/Controls/wm-vscroll) messages. See **GetScrollInfo** for a description of the technique.

If the *nBar* parameter is SB_CTL and the window specified by the *hWnd* parameter is not a system scroll bar control, the system sends the [SBM_SETPOS](https://learn.microsoft.com/windows/desktop/Controls/sbm-setpos) message to the window to set scroll bar information. This allows **SetScrollPos** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_SETPOS** message, the **SetScrollPos** function fails.

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

[GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos)

[GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange)

**Reference**

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)

[SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange)