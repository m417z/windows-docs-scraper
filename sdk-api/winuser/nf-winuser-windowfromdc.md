# WindowFromDC function

## Description

The **WindowFromDC** function returns a handle to the window associated with the specified display device context (DC). Output functions that use the specified device context draw into this window.

## Parameters

### `hDC` [in]

Handle to the device context from which a handle to the associated window is to be retrieved.

## Return value

The return value is a handle to the window associated with the specified DC. If no window is associated with the specified DC, the return value is **NULL**.

## See also

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[GetDCEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdcex)

[GetWindowDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdc)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)