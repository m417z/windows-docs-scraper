# GetGValue macro

## Syntax

```cpp
BYTE GetGValue(
    DWORD rgb
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is the intensity of the green component of the specified RGB color.

## Description

The **GetGValue** macro retrieves an intensity value for the green component of a red, green, blue (RGB) value.

## Parameters

### `rgb`

Specifies an RGB color value.

## Remarks

The intensity value is in the range 0 through 255.

## See also

[Color Macros](https://learn.microsoft.com/windows/desktop/gdi/color-macros)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetBValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbvalue)

[GetRValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrvalue)

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

[PALETTERGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-palettergb)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)