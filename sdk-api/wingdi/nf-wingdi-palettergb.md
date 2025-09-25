# PALETTERGB macro

## Syntax

```cpp
COLORREF PALETTERGB(
    BYTE r,
    BYTE g,
    BYTE b
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is a palette-relative RGB specifier. For output devices that support logical palettes, the system matches a palette-relative RGB value to the nearest color in the logical palette of the device context as though the application had specified an index to that palette entry. If an output device does not support a system palette, the system uses the palette-relative RGB as though it were a conventional RGB value returned by the **RGB** macro.

## Description

The **PALETTERGB** macro accepts three values that represent the relative intensities of red, green, and blue and returns a palette-relative red, green, blue (RGB) specifier consisting of 2 in the high-order byte and an RGB value in the three low-order bytes. An application using a color palette can pass this specifier, instead of an explicit RGB value, to functions that expect a color.

## Parameters

### `r`

The intensity of the red color field.

### `g`

The intensity of the green color field.

### `b`

The intensity of the blue color field.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Macros](https://learn.microsoft.com/windows/desktop/gdi/color-macros)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)