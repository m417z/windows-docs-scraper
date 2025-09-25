# GetWindowDC function

## Description

The **GetWindowDC** function retrieves the device context (DC) for the entire window, including title bar, menus, and scroll bars. A window device context permits painting anywhere in a window, because the origin of the device context is the upper-left corner of the window instead of the client area.

**GetWindowDC** assigns default attributes to the window device context each time it retrieves the device context. Previous attributes are lost.

## Parameters

### `hWnd` [in]

A handle to the window with a device context that is to be retrieved. If this value is **NULL**, **GetWindowDC** retrieves the device context for the entire screen.

If this parameter is **NULL**, **GetWindowDC** retrieves the device context for the primary display monitor. To get the device context for other display monitors, use the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) and [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) functions.

## Return value

If the function succeeds, the return value is a handle to a device context for the specified window.

If the function fails, the return value is **NULL**, indicating an error or an invalid *hWnd* parameter.

## Remarks

**GetWindowDC** is intended for special painting effects within a window's nonclient area. Painting in nonclient areas of any window is not recommended.

The [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function can be used to retrieve the dimensions of various parts of the nonclient area, such as the title bar, menu, and scroll bars.

The [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function can be used to retrieve a device context for the entire screen.

After painting is complete, the [ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc) function must be called to release the device context. Not releasing the window device context has serious effects on painting requested by applications.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc)