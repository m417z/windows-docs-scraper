# GetScrollBarInfo function

## Description

The **GetScrollBarInfo** function retrieves information about the specified scroll bar.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a window associated with the scroll bar whose information is to be retrieved. If the
*idObject* parameter is OBJID_CLIENT,
*hwnd* is a handle to a scroll bar control. Otherwise,
*hwnd* is a handle to a window created with [WS_VSCROLL](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) and/or [WS_HSCROLL](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style.

### `idObject` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the scroll bar object. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **OBJID_CLIENT** | The *hwnd* parameter is a handle to a scroll bar control. |
| **OBJID_HSCROLL** | The horizontal scroll bar of the *hwnd* window. |
| **OBJID_VSCROLL** | The vertical scroll bar of the *hwnd* window. |

### `psbi` [out]

Type: **PSCROLLBARINFO**

Pointer to a [SCROLLBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollbarinfo) structure to receive the information. Before calling **GetScrollBarInfo**, set the
**cbSize** member to
**sizeof**(**SCROLLBARINFO**).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *idObject* is OBJID_CLIENT and the window specified by *hwnd* is not a system scroll bar control, the system sends the [SBM_GETSCROLLBARINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-getscrollbarinfo) message to the window to obtain scroll bar information. This allows **GetScrollBarInfo** to operate on a custom control that mimics a scroll bar. If the window does not handle the **SBM_GETSCROLLBARINFO** message, the **GetScrollBarInfo** function fails.

## See also

[SCROLLBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-scrollbarinfo)