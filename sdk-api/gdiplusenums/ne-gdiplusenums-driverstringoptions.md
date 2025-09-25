# DriverStringOptions enumeration

## Description

The **DriverStringOptions** enumeration specifies the spacing, orientation, and quality of the rendering for driver strings.

## Constants

### `DriverStringOptionsCmapLookup:1`

Specifies that the string array contains Unicode character values.
If this flag is not set, each value in array is interpreted as an index to a font glyph that defines a character to be displayed.

### `DriverStringOptionsVertical:2`

Specifies that the string is displayed vertically.

### `DriverStringOptionsRealizedAdvance:4`

Specifies that the glyph positions are calculated from the position of the first glyph. If this flag is not set, the glyph positions are obtained from an array of coordinates.

### `DriverStringOptionsLimitSubpixel:8`

Specifies that less memory should be used for cache of antialiased glyphs. This also produces lower quality. If this flag isn't set, more memory is used, but the quality is higher.

## See also

[Antialiasing with Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-antialiasing-with-text-use)

[Graphics::DrawDriverString](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawdriverstring)

[Graphics::MeasureDriverString](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-measuredriverstring)