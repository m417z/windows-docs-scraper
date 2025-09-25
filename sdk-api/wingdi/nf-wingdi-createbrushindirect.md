# CreateBrushIndirect function

## Description

The **CreateBrushIndirect** function creates a logical brush that has the specified style, color, and pattern.

## Parameters

### `plbrush` [in]

A pointer to a [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush) structure that contains information about the brush.

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes.

After an application creates a brush by calling **CreateBrushIndirect**, it can select it into any device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function.

A brush created by using a monochrome bitmap (one color plane, one bit per pixel) is drawn using the current text and background colors. Pixels represented by a bit set to 0 are drawn with the current text color; pixels represented by a bit set to 1 are drawn with the current background color.

When you no longer need the brush, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color is done at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex)

[LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)