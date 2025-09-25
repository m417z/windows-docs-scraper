## Description

Represents a value for a font axis. Used when querying and creating font instances (for example, see [IDWriteFontFace5::GetFontAxisValues](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontface5-getfontaxisvalues)).

## Members

### `axisTag`

Type: **[DWRITE_FONT_AXIS_TAG](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_axis_tag)**

The four-character identifier of the font axis (for example, weight, width, slant, italic, and so on).

### `value`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A value for the axis specified in `axisTag`. The meaning and range of the value depends on the semantics of the particular axis. Certain well-known axes have standard ranges and defaults. Here are some examples.

- Weight (1..1000, default == 400)
- Width (>0, default == 100)
- Slant (-90..90, default == -20)
- Italic (0 or 1)

## Remarks

## See also

[DWRITE_FONT_AXIS_TAG enumeration](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_axis_tag)

[DWRITE_FONT_AXIS_RANGE structure](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)