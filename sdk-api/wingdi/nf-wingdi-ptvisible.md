# PtVisible function

## Description

The **PtVisible** function determines whether the specified point is within the clipping region of a device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical units, of the point.

### `y` [in]

The y-coordinate, in logical units, of the point.

## Return value

If the specified point is within the clipping region of the device context, the return value is **TRUE**(1).

If the specified point is not within the clipping region of the device context, the return value is **FALSE**(0).

If the **HDC** is not valid, the return value is (BOOL)-1.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[RectVisible](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectvisible)