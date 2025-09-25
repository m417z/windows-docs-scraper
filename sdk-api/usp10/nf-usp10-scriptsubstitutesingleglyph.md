# ScriptSubstituteSingleGlyph function

## Description

Enables substitution of a single glyph with one alternate form of the same glyph for OpenType processing.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure indicating the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This parameter identifies the shaping engine so that the correct substitute glyph is used.

Alternatively, the application can set this parameter to **NULL** to retrieve unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the script tag for shaping.

### `tagLangSys` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the language tag for shaping.

### `tagFeature` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the feature tag to use for shaping the alternate glyph.

### `lParameter` [in]

Reference to the alternate glyph to substitute. This reference is an index to an array that contains all the alternate glyphs defined in the feature, as illustrated for [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record). The alternate glyph array is one of the items retrieved by [ScriptGetFontAlternateGlyphs](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontalternateglyphs).

### `wGlyphId` [in]

Identifier of the original glyph.

### `pwOutGlyphId` [out]

Pointer to the location in which this function retrieves the identifier of the alternate glyph.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

This function uses one-to-one substitution in which the application can substitute one glyph with one alternate form. Most often, applications use this function to set a bullet or an alternate glyph at the beginning or end of a line.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptGetFontAlternateGlyphs](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontalternateglyphs)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)