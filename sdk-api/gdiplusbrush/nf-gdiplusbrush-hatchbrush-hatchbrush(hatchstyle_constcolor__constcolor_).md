## Description

Creates a **HatchBrush::HatchBrush** object based on a hatch style, a foreground color, and a background color.

## Parameters

### `hatchStyle` [in]

Type: **[HatchStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hatchstyle)**

Element of the [HatchStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hatchstyle) enumeration that specifies the pattern of hatch lines that will be used.

### `foreColor` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a color to use for the hatch lines.

### `backColor` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Optional. Reference to a color to use for the background. The default value is **Color**()(a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object created by the default **Color** constructor).

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[HatchStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hatchstyle)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)