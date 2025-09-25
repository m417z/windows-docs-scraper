# DWRITE_FONT_STYLE enumeration

## Description

Represents the style of a font face as normal, italic, or oblique.

## Constants

### `DWRITE_FONT_STYLE_NORMAL`

Font style : Normal.

### `DWRITE_FONT_STYLE_OBLIQUE`

Font style : Oblique.

### `DWRITE_FONT_STYLE_ITALIC`

Font style : Italic.

## Remarks

Three terms categorize the slant of a font: normal, italic, and oblique.

| Font style | Description |
| --- | --- |
| Normal | The characters in a normal, or roman, font are upright. |
| Italic | The characters in an italic font are truly slanted and appear as they were designed. |
| Oblique | The characters in an oblique font are artificially slanted. |

For Oblique, the slant is achieved by performing a shear transformation on the characters from a normal font. When a true italic font is not available on a computer or printer, an oblique style can be generated from the normal font and used to simulate an italic font.

The following illustration shows the normal, italic, and oblique font styles for the Palatino Linotype font. Notice how the italic font style has a more flowing and visually appealing appearance than the oblique font style, which is simply created by skewing the normal font style version of the text.

![Illustration of normal, italic, and oblique font styles](https://learn.microsoft.com/windows/win32/api/dwrite/images/FontStyle_for_Palatino.png)

**Note** Values other than the ones defined in the enumeration are considered to be invalid, and they are rejected by font API functions.