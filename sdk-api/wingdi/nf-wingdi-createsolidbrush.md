# CreateSolidBrush function

## Description

The **CreateSolidBrush** function creates a logical brush that has the specified solid color.

## Parameters

### `color` [in]

The color of the brush. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HBRUSH** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

A solid brush is a bitmap that the system uses to paint the interiors of filled shapes.

After an application creates a brush by calling **CreateSolidBrush**, it can select that brush into any device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function.

To paint with a system color brush, an application should use `GetSysColorBrush (nIndex)` instead of `CreateSolidBrush(GetSysColor(nIndex))`, because [GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) returns a cached brush instead of allocating a new one.

**ICM:** No color management is done at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

#### Examples

For an example, see [Creating Colored Pens and Brushes](https://learn.microsoft.com/windows/desktop/gdi/creating-colored-pens-and-brushes).

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt)

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)