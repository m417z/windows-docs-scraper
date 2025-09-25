# PALETTEINDEX macro

## Syntax

```cpp
COLORREF PALETTEINDEX(
    WORD i
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is a logical-palette index specifier.

## Description

The **PALETTEINDEX** macro accepts an index to a logical-color palette entry and returns a palette-entry specifier consisting of a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that specifies the color associated with the given index. An application using a logical palette can pass this specifier, instead of an explicit red, green, blue (RGB) value, to GDI functions that expect a color. This allows the function to use the color in the specified palette entry.

## Parameters

### `i`

An index to the palette entry containing the color to be used for a graphics operation.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Macros](https://learn.microsoft.com/windows/desktop/gdi/color-macros)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[PALETTERGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-palettergb)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)