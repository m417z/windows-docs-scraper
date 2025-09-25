# CreateDIBPatternBrush function

## Description

The **CreateDIBPatternBrush** function creates a logical brush that has the pattern specified by the specified device-independent bitmap (DIB). The brush can subsequently be selected into any device context that is associated with a device that supports raster operations.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt) function.

## Parameters

### `h` [in]

A handle to a global memory object containing a packed DIB, which consists of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by an array of bytes defining the pixels of the bitmap.

### `iUsage` [in]

Specifies whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure is initialized and, if so, whether this member contains explicit red, green, blue (RGB) values or indexes into a logical palette. The *fuColorSpec* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | A color table is provided and consists of an array of 16-bit indexes into the logical palette of the device context into which the brush is to be selected. |
| **DIB_RGB_COLORS** | A color table is provided and contains literal RGB values. |

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

When an application selects a two-color DIB pattern brush into a monochrome device context, the system does not acknowledge the colors specified in the DIB; instead, it displays the pattern brush using the current background and foreground colors of the device context. Pixels mapped to the first color of the DIB (offset 0 in the DIB color table) are displayed using the foreground color; pixels mapped to the second color (offset 1 in the color table) are displayed using the background color.

When you no longer need the brush, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color is done at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)