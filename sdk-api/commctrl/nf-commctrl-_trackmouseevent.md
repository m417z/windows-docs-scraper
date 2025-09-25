# _TrackMouseEvent function

## Description

Posts messages when the mouse pointer leaves a window or hovers over a window for a specified amount of time. This function calls [TrackMouseEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackmouseevent) if it exists, otherwise it emulates it.

## Parameters

### `lpEventTrack` [in, out]

Type: **LPTRACKMOUSEEVENT**

A pointer to a [TRACKMOUSEEVENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-trackmouseevent) structure that contains tracking information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, return value is zero.

## See also

**Conceptual**

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Other Resources**

**Reference**

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)

[TRACKMOUSEEVENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-trackmouseevent)

[TrackMouseEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackmouseevent)