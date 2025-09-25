# DRAWSTATEPROC callback function

## Description

The **DrawStateProc** function is an application-defined callback function that renders a complex image for the [DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea) function. The **DRAWSTATEPROC** type defines a pointer to this callback function. **DrawStateProc** is a placeholder for the application-defined function name.

## Parameters

### `hdc` [in]

A handle to the device context to draw in. The device context is a memory device context with a bitmap selected, the dimensions of which are at least as great as those specified by the *cx* and *cy* parameters.

### `lData` [in]

Specifies information about the image, which the application passed to [DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea).

### `wData` [in]

Specifies information about the image, which the application passed to [DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea).

### `cx` [in]

The image width, in device units, as specified by the call to [DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea).

### `cy` [in]

The image height, in device units, as specified by the call to [DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## See also

[DrawState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawstatea)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)