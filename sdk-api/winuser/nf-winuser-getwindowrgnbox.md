# GetWindowRgnBox function

## Description

The **GetWindowRgnBox** function retrieves the dimensions of the tightest bounding rectangle for the window region of a window.

## Parameters

### `hWnd` [in]

Handle to the window.

### `lprc` [out]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the rectangle dimensions, in device units relative to the upper-left corner of the window.

## Return value

The return value specifies the type of the region that the function obtains. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| COMPLEXREGION | The region is more than one rectangle. |
| ERROR | The specified window does not have a region, or an error occurred while attempting to return the region. |
| NULLREGION | The region is empty. |
| SIMPLEREGION | The region is a single rectangle. |

## Remarks

The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region. The coordinates of a window's window region are relative to the upper-left corner of the window, not the client area of the window.

To set the window region of a window, call the [SetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowrgn) function.

## See also

[GetClipBox](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getclipbox)

[GetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowrgn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[SetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowrgn)