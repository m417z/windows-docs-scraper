# TrackMouseEvent function

## Description

Posts messages when the mouse pointer leaves a window or hovers over a window for a specified amount of time.

**Note** The [_TrackMouseEvent](https://learn.microsoft.com/windows/win32/api/commctrl/nf-commctrl-_trackmouseevent) function calls **TrackMouseEvent** if it exists, otherwise **_TrackMouseEvent** emulates **TrackMouseEvent**.

## Parameters

### `lpEventTrack` [in, out]

Type: **LPTRACKMOUSEEVENT**

A pointer to a [TRACKMOUSEEVENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-trackmouseevent) structure that contains tracking information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero .

If the function fails, return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The mouse pointer is considered to be hovering when it stays within a specified rectangle for a specified period of time. Call
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa).
and use the values **SPI_GETMOUSEHOVERWIDTH**, **SPI_GETMOUSEHOVERHEIGHT**, and **SPI_GETMOUSEHOVERTIME** to retrieve the size of the rectangle and the time.

The function can post the following messages.

| Message | Description |
| --- | --- |
| **WM_NCMOUSEHOVER** | The same meaning as [WM_MOUSEHOVER](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousehover) except this is for the nonclient area of the window. |
| **WM_NCMOUSELEAVE** | The same meaning as [WM_MOUSELEAVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mouseleave) except this is for the nonclient area of the window. |
| **WM_MOUSEHOVER** | The mouse hovered over the client area of the window for the period of time specified in a prior call to **TrackMouseEvent**. Hover tracking stops when this message is generated. The application must call **TrackMouseEvent** again if it requires further tracking of mouse hover behavior. |
| **WM_MOUSELEAVE** | The mouse left the client area of the window specified in a prior call to **TrackMouseEvent**. All tracking requested by **TrackMouseEvent** is canceled when this message is generated. The application must call **TrackMouseEvent** when the mouse reenters its window if it requires further tracking of mouse hover behavior. |

## See also

**Conceptual**

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Other Resources**

**Reference**

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)

[TRACKMOUSEEVENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-trackmouseevent)

[_TrackMouseEvent](https://learn.microsoft.com/windows/win32/api/commctrl/nf-commctrl-_trackmouseevent)