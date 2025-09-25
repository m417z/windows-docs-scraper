# RGB macro

## Syntax

```cpp
COLORREF RGB(
    BYTE r,
    BYTE g,
    BYTE b
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is the resultant RGB color as a [COLORREF](https://learn.microsoft.com/windows/win32/gdi/colorref) value.

## Description

The **RGB** macro selects a red, green, blue (RGB) color based on the arguments supplied and the color capabilities of the output device.

## Parameters

### `r`

The intensity of the red color.

### `g`

The intensity of the green color.

### `b`

The intensity of the blue color.

## -return

Type: **[COLORREF](https://learn.microsoft.com/windows/win32/gdi/colorref)**

The COLORREF represented by the given RGB values.

## Remarks

The intensity for each argument is in the range 0 through 255. If all three intensities are zero, the result is black. If all three intensities are 255, the result is white.

To extract the individual values for the red, green, and blue components of a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [GetRValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrvalue), [GetGValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getgvalue), and [GetBValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbvalue) macros, respectively.

When creating or examining a logical palette, use the [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad) structure to define color values and examine individual component values. For more information about using color values in a color palette, see the descriptions of the [PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85)) and [PALETTERGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-palettergb) macros.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Macros](https://learn.microsoft.com/windows/desktop/gdi/color-macros)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetBValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbvalue)

[GetGValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getgvalue)

[GetRValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrvalue)

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

[PALETTERGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-palettergb)

[RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad)