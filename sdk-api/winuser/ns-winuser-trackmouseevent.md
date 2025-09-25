# TRACKMOUSEEVENT structure

## Description

Used by the [TrackMouseEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackmouseevent) function to track when the mouse pointer leaves a window or hovers over a window for a specified amount of time.

## Members

### `cbSize`

Type: **DWORD**

The size of the **TRACKMOUSEEVENT** structure, in bytes.

### `dwFlags`

Type: **DWORD**

The services requested. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **TME_CANCEL**<br><br>0x80000000 | The caller wants to cancel a prior tracking request. The caller should also specify the type of tracking that it wants to cancel. For example, to cancel hover tracking, the caller must pass the **TME_CANCEL** and **TME_HOVER** flags. |
| **TME_HOVER**<br><br>0x00000001 | The caller wants hover notification. Notification is delivered as a [WM_MOUSEHOVER](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousehover) message. <br><br>If the caller requests hover tracking while hover tracking is already active, the hover timer will be reset.<br><br>This flag is ignored if the mouse pointer is not over the specified window or area. |
| **TME_LEAVE**<br><br>0x00000002 | The caller wants leave notification. Notification is delivered as a [WM_MOUSELEAVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mouseleave) message. If the mouse is not over the specified window or area, a leave notification is generated immediately and no further tracking is performed. |
| **TME_NONCLIENT**<br><br>0x00000010 | The caller wants hover and leave notification for the nonclient areas. Notification is delivered as [WM_NCMOUSEHOVER](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncmousehover) and [WM_NCMOUSELEAVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncmouseleave) messages. |
| **TME_QUERY**<br><br>0x40000000 | The function fills in the structure instead of treating it as a tracking request. The structure is filled such that had that structure been passed to [TrackMouseEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackmouseevent), it would generate the current tracking. The only anomaly is that the hover time-out returned is always the actual time-out and not **HOVER_DEFAULT**, if **HOVER_DEFAULT** was specified during the original **TrackMouseEvent** request. |

### `hwndTrack`

Type: **HWND**

A handle to the window to track.

### `dwHoverTime`

Type: **DWORD**

The hover time-out (if **TME_HOVER** was specified in **dwFlags**), in milliseconds. Can be **HOVER_DEFAULT**, which means to use the system default hover time-out.

## Remarks

The system default hover time-out is initially the menu drop-down time, which is 400 milliseconds. You can call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) and use **SPI_GETMOUSEHOVERTIME** to retrieve the default hover time-out.

The system default hover rectangle is the same as the double-click rectangle. You can call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) and use **SPI_GETMOUSEHOVERWIDTH** and **SPI_GETMOUSEHOVERHEIGHT** to retrieve the size of the rectangle within which the mouse pointer has to stay for [TrackMouseEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackmouseevent) to generate a [WM_MOUSEHOVER](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousehover) message.

## See also

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)