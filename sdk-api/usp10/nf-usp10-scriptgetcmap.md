# ScriptGetCMap function

## Description

Retrieves the glyph indexes of the Unicode characters in a string according to either the TrueType cmap table or the standard cmap table implemented for old-style fonts.

## Parameters

### `hdc` [in]

Optional. Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `pwcInChars` [in]

Pointer to a string of Unicode characters.

### `cChars` [in]

Number of Unicode characters in the string indicated by *pwcInChars*.

### `dwFlags` [in]

Flags specifying any special handling of the glyphs. By default, the glyphs are provided in logical order with no special handling. This parameter can have the following value.

| Value | Meaning |
| --- | --- |
| **SGCM_RTL** | The glyph array indicated by *pwOutGlyphs* should contain mirrored glyphs for those glyphs that have a mirrored equivalent. |

### `pwOutGlyphs` [out]

Pointer to a buffer in which the function retrieves an array of glyph indexes. This buffer should be of the same length as the input buffer indicated by *pwcInChars*. Each code point maps to a single glyph.

## Return value

Returns S_OK if all Unicode code points are present in the font. The function returns one of the nonzero HRESULT values listed below if it does not succeed.

| Return value | Meaning |
| --- | --- |
| E_HANDLE | The font or the operating system does not support glyph indexes. |
| S_FALSE | Some of the Unicode code points were mapped to the default glyph. |

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

This function can be used to determine the characters in a run that are supported by the selected font. The application can scan the retrieved glyph buffer, looking for the default glyph to determine characters that are not available. The application should determine the default glyph index for the selected font by calling [ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties).

The return value for this function indicates the presence of any missing glyphs.

**Note** The function assumes a 1:1 relationship between the elements in the input and output arrays. However, the function does not support this relationship for UTF-16 surrogate pairs. For a surrogate pair, the function does not retrieve the glyph index for the supplementary-plane character. Similarly, the function does not support Unicode Variation-Selector (VS) sequences, each of which consists of a Unicode graphic character followed by one of a set of VARIATION SELECTOR characters to select a particular glyph representation for that graphic character. For a VS sequence, the function retrieves the glyph index for the default glyph mapped by the cmap for the two characters, instead of the glyph index for the particular glyph for the VS sequence.

Some code points can be rendered by a combination of glyphs, as well as by a single glyph, for example, 00C9; LATIN CAPITAL LETTER E WITH ACUTE. In this case, if the font supports the capital E glyph and the acute glyph, but not a single glyph for 00C9, **ScriptGetCMap** shows that 00C9 is unsupported. To determine the font support for a string that contains these kinds of code points, the application can call [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape). If the function returns S_OK, the application should check the output for missing glyphs.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)