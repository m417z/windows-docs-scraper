# DragDetect function

## Description

Captures the mouse and tracks its movement until the user releases the left button, presses the ESC key, or moves the mouse outside the drag rectangle around the specified point. The width and height of the drag rectangle are specified by the **SM_CXDRAG** and **SM_CYDRAG** values returned by the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window receiving mouse input.

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Initial position of the mouse, in screen coordinates. The function determines the coordinates of the drag rectangle by using this point.

## Return value

Type: **BOOL**

If the user moved the mouse outside of the drag rectangle while holding down the left button, the return value is nonzero.

If the user did not move the mouse outside of the drag rectangle while holding down the left button, the return value is zero.

## Remarks

The system metrics for the drag rectangle are configurable, allowing for larger or smaller drag rectangles.

## See also

**Conceptual**

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**