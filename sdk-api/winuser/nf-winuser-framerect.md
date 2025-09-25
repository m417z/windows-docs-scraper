# FrameRect function

## Description

The **FrameRect** function draws a border around the specified rectangle by using the specified brush. The width and height of the border are always one logical unit.

## Parameters

### `hDC` [in]

A handle to the device context in which the border is drawn.

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the upper-left and lower-right corners of the rectangle.

### `hbr` [in]

A handle to the brush used to draw the border.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The brush identified by the *hbr* parameter must have been created by using the [CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush), [CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush), or [CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush) function, or retrieved by using the [GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject) function.

If the **bottom** member of the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure is less than the **top** member, or if the **right** member is less than the **left** member, the function does not draw the rectangle.

## See also

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)