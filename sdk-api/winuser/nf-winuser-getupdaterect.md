# GetUpdateRect function

## Description

The **GetUpdateRect** function retrieves the coordinates of the smallest rectangle that completely encloses the update region of the specified window. **GetUpdateRect** retrieves the rectangle in logical coordinates. If there is no update region, **GetUpdateRect** retrieves an empty rectangle (sets all coordinates to zero).

## Parameters

### `hWnd` [in]

Handle to the window whose update region is to be retrieved.

### `lpRect` [out]

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the coordinates, in device units, of the enclosing rectangle.

An application can set this parameter to **NULL** to determine whether an update region exists for the window. If this parameter is **NULL**, **GetUpdateRect** returns nonzero if an update region exists, and zero if one does not. This provides a simple and efficient means of determining whether a **WM_PAINT** message resulted from an invalid area.

### `bErase` [in]

Specifies whether the background in the update region is to be erased. If this parameter is **TRUE** and the update region is not empty, **GetUpdateRect** sends a **WM_ERASEBKGND** message to the specified window to erase the background.

## Return value

If the update region is not empty, the return value is nonzero.

If there is no update region, the return value is zero.

## Remarks

The update rectangle retrieved by the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function is identical to that retrieved by **GetUpdateRect**.

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) automatically validates the update region, so any call to **GetUpdateRect** made immediately after the call to **BeginPaint** retrieves an empty update region.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[GetUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdatergn)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)

[ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect)