# IDWriteFontFace1::GetUnicodeRanges

## Description

Retrieves a list of character ranges supported by a font.

## Parameters

### `maxRangeCount`

Type: **UINT32**

Maximum number of character ranges passed
in from the client.

### `unicodeRanges` [out, optional]

Type: **[DWRITE_UNICODE_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_unicode_range)***

An array of [DWRITE_UNICODE_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_unicode_range) structures that are filled with the character ranges.

### `actualRangeCount` [out]

Type: **UINT32***

A pointer to the actual number of character ranges,
regardless of the maximum count.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method executed successfully. |
| E_NOT_SUFFICIENT_BUFFER | The buffer is too small. The *actualRangeCount* was more than the *maxRangeCount*. |

## Remarks

A
list of character ranges supported by the font is
useful for scenarios like character picking, glyph display, and
efficient font selection lookup. This is similar to GDI's
[GetFontUnicodeRanges](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getfontunicoderanges), except that it returns the full Unicode range,
not just 16-bit UCS-2.

These ranges are from the cmap, not the OS/2::ulCodePageRange1.

If this method is unavailable, you can use the [IDWriteFontFace::GetGlyphIndices](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontface-getglyphindices) method to check for missing glyphs. The method returns the 0 index for glyphs that aren't present in the font.

 The [IDWriteFont::HasCharacter](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefont-hascharacter) method is often simpler in cases where you need to check a single character or a series of single characters in succession, such as in font fallback.

## See also

[IDWriteFontFace1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)