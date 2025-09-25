# PatBlt function

## Description

The **PatBlt** function paints the specified rectangle using the brush that is currently selected into the specified device context. The brush color and the surface color or colors are combined by using the specified raster operation.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical units, of the upper-left corner of the rectangle to be filled.

### `y` [in]

The y-coordinate, in logical units, of the upper-left corner of the rectangle to be filled.

### `w` [in]

The width, in logical units, of the rectangle.

### `h` [in]

The height, in logical units, of the rectangle.

### `rop` [in]

The raster operation code. This code can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PATCOPY** | Copies the specified pattern into the destination bitmap. |
| **PATINVERT** | Combines the colors of the specified pattern with the colors of the destination rectangle by using the Boolean XOR operator. |
| **DSTINVERT** | Inverts the destination rectangle. |
| **BLACKNESS** | Fills the destination rectangle using the color associated with index 0 in the physical palette. (This color is black for the default physical palette.) |
| **WHITENESS** | Fills the destination rectangle using the color associated with index 1 in the physical palette. (This color is white for the default physical palette.) |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The values of the *dwRop* parameter for this function are a limited subset of the full 256 ternary raster-operation codes; in particular, an operation code that refers to a source rectangle cannot be used.

Not all devices support the **PatBlt** function. For more information, see the description of the RC_BITBLT capability in the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function.

#### Examples

For an example, see "Example of Menu-Item Bitmaps" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)