# ShowScrollBar function

## Description

The **ShowScrollBar** function shows or hides the specified scroll bar.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a scroll bar control or a window with a standard scroll bar, depending on the value of the
*wBar* parameter.

### `wBar` [in]

Type: **int**

Specifies the scroll bar(s) to be shown or hidden. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_BOTH** | Shows or hides a window's standard horizontal and vertical scroll bars. |
| **SB_CTL** | Shows or hides a scroll bar control. The *hwnd* parameter must be the handle to the scroll bar control. |
| **SB_HORZ** | Shows or hides a window's standard horizontal scroll bars. |
| **SB_VERT** | Shows or hides a window's standard vertical scroll bar. |

### `bShow` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the scroll bar is shown or hidden. If this parameter is **TRUE**, the scroll bar is shown; otherwise, it is hidden.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You should not call this function to hide a scroll bar while processing a scroll bar message.

## See also

[EnableScrollBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablescrollbar)