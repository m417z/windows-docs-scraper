## Description

Describes a color transformation matrix that a magnifier control uses to apply a color effect to magnified screen content.

## Members

### `transform`

Type: **float [5] [5]**

The color transformation matrix.

## Remarks

The values in the matrix are for red, blue, green, alpha, and color translation. For more information, see
[Using a Color Matrix to Transform a Single Color](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-color-matrix-to-transform-a-single-color-use) in the Windows GDI+ documentation.

## See also

[MagGetColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetcoloreffect)

[MagSetColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetcoloreffect)