# TRIVERTEX structure

## Description

The **TRIVERTEX** structure contains color information and position information.

## Members

### `x`

The x-coordinate, in logical units, of the upper-left corner of the rectangle.

### `y`

The y-coordinate, in logical units, of the upper-left corner of the rectangle.

### `Red`

The color information at the point of x, y.

### `Green`

The color information at the point of x, y.

### `Blue`

The color information at the point of x, y.

### `Alpha`

The color information at the point of x, y.

## Remarks

In the **TRIVERTEX** structure, x and y indicate position in the same manner as in the [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure contained in the wtypes.h header file. **Red**, **Green**, **Blue**, and **Alpha** members indicate color information at the point x, y. The color information of each channel is specified as a value from 0x0000 to 0xff00. This allows higher color resolution for an object that has been split into small triangles for display. The **TRIVERTEX** structure contains information needed by the *pVertex* parameter of [GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill).

#### Examples

For an example of the use of this structure, see [Drawing a Shaded Triangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-triangle) or [Drawing a Shaded Rectangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-rectangle).

## See also

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill)

[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)