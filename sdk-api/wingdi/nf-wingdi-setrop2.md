# SetROP2 function

## Description

The **SetROP2** function sets the current foreground mix mode. GDI uses the foreground mix mode to combine pens and interiors of filled objects with the colors already on the screen. The foreground mix mode defines how colors from the brush or pen and the colors in the existing image are to be combined.

## Parameters

### `hdc` [in]

A handle to the device context.

### `rop2` [in]

The mix mode. This parameter can be one of the following values.

| Mix mode | Meaning |
| --- | --- |
| **R2_BLACK** | Pixel is always 0. |
| **R2_COPYPEN** | Pixel is the pen color. |
| **R2_MASKNOTPEN** | Pixel is a combination of the colors common to both the screen and the inverse of the pen. |
| **R2_MASKPEN** | Pixel is a combination of the colors common to both the pen and the screen. |
| **R2_MASKPENNOT** | Pixel is a combination of the colors common to both the pen and the inverse of the screen. |
| **R2_MERGENOTPEN** | Pixel is a combination of the screen color and the inverse of the pen color. |
| **R2_MERGEPEN** | Pixel is a combination of the pen color and the screen color. |
| **R2_MERGEPENNOT** | Pixel is a combination of the pen color and the inverse of the screen color. |
| **R2_NOP** | Pixel remains unchanged. |
| **R2_NOT** | Pixel is the inverse of the screen color. |
| **R2_NOTCOPYPEN** | Pixel is the inverse of the pen color. |
| **R2_NOTMASKPEN** | Pixel is the inverse of the R2_MASKPEN color. |
| **R2_NOTMERGEPEN** | Pixel is the inverse of the R2_MERGEPEN color. |
| **R2_NOTXORPEN** | Pixel is the inverse of the R2_XORPEN color. |
| **R2_WHITE** | Pixel is always 1. |
| **R2_XORPEN** | Pixel is a combination of the colors in the pen and in the screen, but not in both. |

## Return value

If the function succeeds, the return value specifies the previous mix mode.

If the function fails, the return value is zero.

## Remarks

Mix modes define how GDI combines source and destination colors when drawing with the current pen. The mix modes are binary raster operation codes, representing all possible Boolean functions of two variables, using the binary operations AND, OR, and XOR (exclusive OR), and the unary operation NOT. The mix mode is for raster devices only; it is not available for vector devices.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[GetROP2](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrop2)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)