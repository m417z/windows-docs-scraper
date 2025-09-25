# DWRITE_FONT_METRICS1 structure

## Description

The **DWRITE_FONT_METRICS1** structure specifies the metrics that are applicable to all glyphs within the font face.

## Members

### `glyphBoxLeft`

Left edge of accumulated bounding blackbox of all glyphs in the font.

### `glyphBoxTop`

Top edge of accumulated bounding blackbox of all glyphs in the font.

### `glyphBoxRight`

Right edge of accumulated bounding blackbox of all glyphs in the font.

### `glyphBoxBottom`

Bottom edge of accumulated bounding blackbox of all glyphs in the font.

### `subscriptPositionX`

Horizontal position of the subscript relative to the baseline origin. This is typically negative (to the left) in italic and oblique fonts, and zero in regular fonts.

### `subscriptPositionY`

Vertical position of the subscript relative to the baseline. This is typically negative.

### `subscriptSizeX`

Horizontal size of the subscript em box in design units, used to scale the simulated subscript relative to the full em box size. This is the numerator of the scaling ratio where denominator is the design units per em. If this member is zero, the font does not specify a scale factor, and the client uses its own policy.

### `subscriptSizeY`

Vertical size of the subscript em box in design units, used to scale the simulated subscript relative to the full em box size. This is the numerator of the scaling ratio where denominator is the design units per em. If this member is zero, the font does not specify a scale factor, and the client uses its own policy.

### `superscriptPositionX`

Horizontal position of the superscript relative to the baseline origin. This is typically positive (to the right) in italic and oblique fonts, and zero in regular fonts.

### `superscriptPositionY`

Vertical position of the superscript relative to the baseline. This is typically positive.

### `superscriptSizeX`

Horizontal size of the superscript em box in design units, used to scale the simulated superscript relative to the full em box size. This is the numerator of the scaling ratio where denominator is the design units per em. If this member is zero, the font does not specify a scale factor, and the client should use its own policy.

### `superscriptSizeY`

Vertical size of the superscript em box in design units, used to scale the simulated superscript relative to the full em box size. This is the numerator of the scaling ratio where denominator is the design units per em. If this member is zero, the font does not specify a scale factor, and the client should use its own policy.

### `hasTypographicMetrics`

A Boolean value that indicates that the ascent, descent, and lineGap are based on newer 'typographic' values in the font, rather than legacy values.

### `DWRITE_FONT_METRICS`

## Remarks

**DWRITE_FONT_METRICS1** inherits from [DWRITE_FONT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_metrics):

``` syntax

struct DWRITE_FONT_METRICS1 : public DWRITE_FONT_METRICS
{
...
};
```

## See also

[IDWriteFont1::GetMetrics](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefont1-getmetrics)

[IDWriteFontFace1::GetGdiCompatibleMetrics](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getgdicompatiblemetrics)

[IDWriteFontFace1::GetMetrics](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefontface1-getmetrics)