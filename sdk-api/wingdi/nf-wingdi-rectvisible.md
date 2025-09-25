# RectVisible function

## Description

The **RectVisible** function determines whether any part of the specified rectangle lies within the clipping region of a device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lprect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the specified rectangle.

## Return value

If the current transform does not have a rotation and the rectangle lies within the clipping region, the return value is **TRUE** (1).

If the current transform does not have a rotation and the rectangle does not lie within the clipping region, the return value is **FALSE** (0).

If the current transform has a rotation and the rectangle lies within the clipping region, the return value is 2.

If the current transform has a rotation and the rectangle does not lie within the clipping region, the return value is 1.

All other return values are considered error codes. If the any parameter is not valid, the return value is undefined.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[PtVisible](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ptvisible)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)