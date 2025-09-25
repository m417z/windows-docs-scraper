# FillRect function

## Description

The **FillRect** function fills a rectangle by using the specified brush. This function includes the left and top borders, but excludes the right and bottom borders of the rectangle.

## Parameters

### `hDC` [in]

A handle to the device context.

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the rectangle to be filled.

### `hbr` [in]

A handle to the brush used to fill the rectangle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The brush identified by the *hbr* parameter may be either a handle to a logical brush or a color value. If specifying a handle to a logical brush, call one of the following functions to obtain the handle: [CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush), [CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush), or [CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush). Additionally, you may retrieve a handle to one of the stock brushes by using the [GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject) function. If specifying a color value for the *hbr* parameter, it must be one of the standard system colors (the value 1 must be added to the chosen color). For example:

```cpp

FillRect(hdc, &rect, (HBRUSH) (COLOR_WINDOW+1));

```

For a list of all the standard system colors, see [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor).

When filling the specified rectangle, **FillRect** does not include the rectangle's right and bottom sides. GDI fills a rectangle up to, but not including, the right column and bottom row, regardless of the current mapping mode.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)