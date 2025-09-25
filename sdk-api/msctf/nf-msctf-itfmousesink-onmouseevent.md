# ITfMouseSink::OnMouseEvent

## Description

Called when a mouse event occurs over a range of text.

## Parameters

### `uEdge` [in]

Contains the offset, in characters, of the mouse position from the start of the range of text. For more information, see the Remarks section.

### `uQuadrant` [in]

Contains the zero-based quadrant index, relative to the edge, that the mouse position lies in. For more information, see the Remarks section.

### `dwBtnStatus` [in]

Indicates the mouse button state at the time of the event. See the *wParam* parameter of the [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message for possible values.

### `pfEaten` [out]

Pointer to a BOOL that, on exit, indicates if the mouse event was handled. If this value receives **TRUE**, the mouse event was handled. If this value is **FALSE**, the mouse event was not handled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The caller should translate double-click events into multiple mouse button down events. This enables a text service to detect double-click events even if the context window does not support double-clicks.

*uEdge* contains the offset, in characters, of the mouse position from the start of the text range. The mouse position is always rounded to the closest edge. Each edge is divided into four equal quadrants with two quadrants preceding the edge and two quadrants following the edge. *uQuadrant* contains the zero-based quadrant index of the mouse position. In the figure below, point "X" is in quadrant 2 of edge 1 and point "Y" is in quadrant 1 of edge 3.

![Quadrant relationship to edge of a range of text](https://learn.microsoft.com/windows/win32/api/msctf/images/mousedge.gif)

## See also

[ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink)

[ITfMouseTracker::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetracker-advisemousesink)

[ITfMouseTrackerACP::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetrackeracp-advisemousesink)

[WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove)