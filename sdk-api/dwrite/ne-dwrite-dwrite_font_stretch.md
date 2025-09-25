# DWRITE_FONT_STRETCH enumeration

## Description

Represents the degree to which a font has been stretched compared to a font's normal aspect ratio.The enumerated values correspond to the *usWidthClass* definition in the OpenType specification. The usWidthClass represents an integer value between 1 and 9—lower values indicate narrower widths; higher values indicate wider widths.

## Constants

### `DWRITE_FONT_STRETCH_UNDEFINED:0`

Predefined font stretch : Not known (0).

### `DWRITE_FONT_STRETCH_ULTRA_CONDENSED:1`

Predefined font stretch : Ultra-condensed (1).

### `DWRITE_FONT_STRETCH_EXTRA_CONDENSED:2`

Predefined font stretch : Extra-condensed (2).

### `DWRITE_FONT_STRETCH_CONDENSED:3`

Predefined font stretch : Condensed (3).

### `DWRITE_FONT_STRETCH_SEMI_CONDENSED:4`

Predefined font stretch : Semi-condensed (4).

### `DWRITE_FONT_STRETCH_NORMAL:5`

Predefined font stretch : Normal (5).

### `DWRITE_FONT_STRETCH_MEDIUM:5`

Predefined font stretch : Medium (5).

### `DWRITE_FONT_STRETCH_SEMI_EXPANDED:6`

Predefined font stretch : Semi-expanded (6).

### `DWRITE_FONT_STRETCH_EXPANDED:7`

Predefined font stretch : Expanded (7).

### `DWRITE_FONT_STRETCH_EXTRA_EXPANDED:8`

Predefined font stretch : Extra-expanded (8).

### `DWRITE_FONT_STRETCH_ULTRA_EXPANDED:9`

Predefined font stretch : Ultra-expanded (9).

## Remarks

A font stretch describes the degree to which a font form is stretched from its normal aspect ratio, which is the original width to height ratio specified for the glyphs in the font.
The following illustration shows an example of Normal and Condensed stretches for the Rockwell Bold typeface.

![Illustration of “D2D” text in Normal and Condensed font stretch](https://learn.microsoft.com/windows/win32/api/dwrite/images/FontStretch_for_RockwellBold.png)

**Note** Values other than the ones defined in the enumeration are considered to be invalid, and are rejected by font API functions.