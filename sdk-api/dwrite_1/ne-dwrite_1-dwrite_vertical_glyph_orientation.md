# DWRITE_VERTICAL_GLYPH_ORIENTATION enumeration

## Description

The **DWRITE_VERTICAL_GLYPH_ORIENTATION** enumeration contains values that specify the desired kind of glyph orientation for the text.

## Constants

### `DWRITE_VERTICAL_GLYPH_ORIENTATION_DEFAULT`

The default glyph orientation. In vertical layout, naturally horizontal scripts (Latin, Thai, Arabic, Devanagari) rotate 90 degrees clockwise, while ideographic scripts (Chinese, Japanese, Korean) remain upright, 0 degrees.

### `DWRITE_VERTICAL_GLYPH_ORIENTATION_STACKED`

Stacked glyph orientation. Ideographic scripts and scripts that permit stacking (Latin, Hebrew) are stacked in vertical reading layout. Connected scripts (Arabic, Syriac, 'Phags-pa, Ogham), which would otherwise look broken if glyphs were kept at 0 degrees, remain connected and rotate.

## Remarks

The client specifies a **DWRITE_VERTICAL_GLYPH_ORIENTATION**-typed value to the analyzer as the desired orientation.

**Note** This is the client preference, and the constraints of the script determine the final presentation.

## See also

[IDWriteTextAnalysisSource1::GetVerticalGlyphOrientation](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalysissource1-getverticalglyphorientation)