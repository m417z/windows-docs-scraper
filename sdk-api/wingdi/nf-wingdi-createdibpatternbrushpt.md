# CreateDIBPatternBrushPt function

## Description

The **CreateDIBPatternBrushPt** function creates a logical brush that has the pattern specified by the device-independent bitmap (DIB).

## Parameters

### `lpPackedDIB` [in]

A pointer to a packed DIB consisting of a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure immediately followed by an array of bytes defining the pixels of the bitmap.

### `iUsage` [in]

Specifies whether the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contains a valid color table and, if so, whether the entries in this color table contain explicit red, green, blue (RGB) values or palette indexes. The *iUsage* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | A color table is provided and consists of an array of 16-bit indexes into the logical palette of the device context into which the brush is to be selected. |
| **DIB_RGB_COLORS** | A color table is provided and contains literal RGB values. |

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes.

After an application creates a brush by calling **CreateDIBPatternBrushPt**, it can select that brush into any device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function.

When you no longer need the brush, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color is done at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)