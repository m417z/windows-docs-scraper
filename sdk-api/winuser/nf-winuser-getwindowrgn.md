# GetWindowRgn function

## Description

The **GetWindowRgn** function obtains a copy of the window region of a window. The window region of a window is set by calling the [SetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowrgn) function. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region

## Parameters

### `hWnd` [in]

Handle to the window whose window region is to be obtained.

### `hRgn` [in]

Handle to the region which will be modified to represent the window region.

## Return value

The return value specifies the type of the region that the function obtains. It can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | The region is empty. |
| **SIMPLEREGION** | The region is a single rectangle. |
| **COMPLEXREGION** | The region is more than one rectangle. |
| **ERROR** | The specified window does not have a region, or an error occurred while attempting to return the region. |

## Remarks

The coordinates of a window's window region are relative to the upper-left corner of the window, not the client area of the window.

To set the window region of a window, call the [SetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowrgn) function.

#### Examples

The following code shows how you pass in the handle of an existing region.

```cpp

HRGN hrgn = CreateRectRgn(0,0,0,0);
int regionType = GetWindowRgn(hwnd, hrgn);
if (regionType != ERROR)
{
/* hrgn contains window region */
}
DeleteObject(hrgn); /* finished with region */

```

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowrgn)