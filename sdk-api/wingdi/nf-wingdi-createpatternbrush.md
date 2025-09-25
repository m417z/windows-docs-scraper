# CreatePatternBrush function

## Description

The **CreatePatternBrush** function creates a logical brush with the specified bitmap pattern. The bitmap can be a DIB section bitmap, which is created by the **CreateDIBSection** function, or it can be a device-dependent bitmap.

## Parameters

### `hbm` [in]

A handle to the bitmap to be used to create the logical brush.

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

A pattern brush is a bitmap that the system uses to paint the interiors of filled shapes.

After an application creates a brush by calling **CreatePatternBrush**, it can select that brush into any device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function.

You can delete a pattern brush without affecting the associated bitmap by using the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function. Therefore, you can then use this bitmap to create any number of pattern brushes.

A brush created by using a monochrome (1 bit per pixel) bitmap has the text and background colors of the device context to which it is drawn. Pixels represented by a 0 bit are drawn with the current text color; pixels represented by a 1 bit are drawn with the current background color.

**ICM:** No color is done at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

#### Examples

For an example, see [Using Brushes](https://learn.microsoft.com/windows/desktop/gdi/using-brushes).

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap)

[CreateBitmapIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmapindirect)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex)

[LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)