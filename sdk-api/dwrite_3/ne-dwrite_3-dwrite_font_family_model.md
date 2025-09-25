## Description

Defines constants that specify how font families are grouped together. Used by [IDWriteFontCollection2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontcollection2), for example.

## Constants

### `DWRITE_FONT_FAMILY_MODEL_TYPOGRAPHIC`

Families are grouped by the typographic family name preferred by the font author. The family can contain as many faces as the font author wants. This corresponds to [DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_property_id).

### `DWRITE_FONT_FAMILY_MODEL_WEIGHT_STRETCH_STYLE`

Families are grouped by the weight-stretch-style family name, where all faces that differ only by those three axes are grouped into the same family, but any other axes go into a distinct family. For example, the Sitka family with six different optical sizes yields six separate families (Sitka Caption, Display, Text, Subheading, Heading, Banner...). This corresponds to [DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_property_id).

## Remarks

## See also