# GRAYSTRINGPROC callback function

## Description

The **OutputProc** function is an application-defined callback function used with the [GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa) function. It is used to draw a string. The **GRAYSTRINGPROC** type defines a pointer to this callback function. **OutputProc** is a placeholder for the application-defined or library-defined function name.

## Parameters

### `unnamedParam1`

A handle to a device context with a bitmap of at least the width and height specified by the *nWidth* and *nHeight* parameters passed to [GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa).

### `unnamedParam2`

A pointer to the string to be drawn.

### `unnamedParam3`

The length, in characters, of the string.

## Return value

If it succeeds, the callback function should return **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

The callback function must draw an image relative to the coordinates (0,0).

## See also

[GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)