# SelectObject function

## Description

The **SelectObject** function selects an object into the specified device context (DC). The new object replaces the previous object of the same type.

## Parameters

### `hdc` [in]

A handle to the DC.

### `h` [in]

A handle to the object to be selected. The specified object must have been created by using one of the following functions.

| Object | Functions |
| --- | --- |
| **Bitmap** | [CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap), [CreateBitmapIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmapindirect), [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap), [CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap), [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)<br><br>Bitmaps can only be selected into memory DC's. A single bitmap cannot be selected into more than one DC at the same time. |
| **Brush** | [CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect), [CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush), [CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt), [CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush), [CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush), [CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush) |
| **Font** | [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta), [CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta) |
| **Pen** | [CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen), [CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect) |
| **Region** | [CombineRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-combinergn), [CreateEllipticRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgn), [CreateEllipticRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgnindirect), [CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn), [CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn), [CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect) |

## Return value

If the selected object is not a region and the function succeeds, the return value is a handle to the object being replaced. If the selected object is a region and the function succeeds, the return value is one of the following values.

| Value | Meaning |
| --- | --- |
| SIMPLEREGION | Region consists of a single rectangle. |
| COMPLEXREGION | Region consists of more than one rectangle. |
| NULLREGION | Region is empty. |

If an error occurs and the selected object is not a region, the return value is **NULL**. Otherwise, it is HGDI_ERROR.

## Remarks

This function returns the previously selected object of the specified type. An application should always replace a new object with the original, default object after it has finished drawing with the new object.

An application cannot select a single bitmap into more than one DC at a time.

**ICM:** If the object being selected is a brush or a pen, color management is performed.

#### Examples

For an example, see [Setting the Pen or Brush Color](https://learn.microsoft.com/windows/desktop/gdi/setting-the-pen-or-brush-color).

## See also

[CombineRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-combinergn)

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap)

[CreateBitmapIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmapindirect)

[CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[CreateEllipticRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgn)

[CreateEllipticRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgnindirect)

[CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta)

[CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)

[SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette)