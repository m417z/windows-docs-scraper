# DIBINDEX macro

## Syntax

```cpp
LONG DIBINDEX(
    WORD n
);
```

## Return value

Type: **LONG**

The return value is a color table index specifier in the form of a 32-bit [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value.

## Description

The **DIBINDEX** macro takes an index to an entry in a DIB color table and returns a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that specifies the color associated with the given index. An application using a device context with a DIB section selected into it can pass this specifier, instead of an explicit red, green, blue (RGB) value, to GDI functions that expect a color. This allows the function to use the color at the specified color table index.

## Parameters

### `n`

Specifies an index to the color table entry containing the color to be used for a graphics operation.

## Remarks

**DIBINDEX** indexes colors in a DIB color table in a manner similar to the way [PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85)) indexes colors in a logical palette.

**DIBINDEX** also works with 16-bit bitmaps and device contexts (DCs).

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Macros](https://learn.microsoft.com/windows/desktop/gdi/color-macros)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)