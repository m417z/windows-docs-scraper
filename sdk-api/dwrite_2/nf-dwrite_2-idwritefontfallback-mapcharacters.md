# IDWriteFontFallback::MapCharacters

## Description

Determines an appropriate font to use to render the beginning range of text.

## Parameters

### `analysisSource`

Type: **[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)***

The text source implementation holds the text and locale.

### `textPosition`

Type: **UINT32**

Starting position to analyze.

### `textLength`

Type: **UINT32**

Length of the text to analyze.

### `baseFontCollection` [in, optional]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)***

Default font collection to use.

### `baseFamilyName` [in, optional]

Type: **const wchar_t***

Family name of the base font. If you pass null, no matching will be done against the family.

### `baseWeight`

Type: **[DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight)**

The desired weight.

### `baseStyle`

Type: **[DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style)**

The desired style.

### `baseStretch`

Type: **[DWRITE_FONT_STRETCH](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_stretch)**

The desired stretch.

### `mappedLength` [out]

Type: **UINT32***

Length of text mapped to the mapped font. This will always be less than or equal to the text length and greater than zero (if the text length is non-zero) so the caller advances at least one character.

### `mappedFont` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

The font that should be used to render the first *mappedLength* characters of the text. If it returns NULL, that means that no font can render the text, and *mappedLength* is the number of characters to skip (rendered with a missing
glyph).

### `scale` [out]

Type: **FLOAT***

Scale factor to multiply the em size of the returned font by.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallback)