# ScriptGetFontAlternateGlyphs function

## Description

Retrieves a list of alternate glyphs for a specified character that can be accessed through a specified OpenType feature.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure defining the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This parameter identifies the shaping engine, so that the array of alternate glyphs can be created with the correct scope.

Alternatively, the application can set this parameter to **NULL** to receive unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the script tag associated with alternate glyphs.

### `tagLangSys` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the language tag associated with alternate glyphs.

### `tagFeature` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the feature tag associated with alternate glyphs.

### `wGlyphId` [in]

The identifier of the original glyph mapped from the character map table.

### `cMaxAlternates` [in]

Length of the array specified by *pAlternateGlyphs*.

### `pAlternateGlyphs` [out]

Pointer to buffer in which this function retrieves an array of glyph identifiers. The array includes the original glyph, followed by alternate glyphs. The first element is always the original glyph. Alternate forms are identified by an index into the array. The index is a value greater than one and less than the value of *pcAlternates*.

When the user chooses an alternate form from the user interface, the alternate glyph is applied to the corresponding character and the rendering is reformatted.

### `pcAlternates` [out]

Pointer to the number of elements in the array specified by *pAlternateGlyphs*.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

If the number of alternate glyphs exceeds the value of *cMaxAlternates*, the function fails with E_OUTOFMEMORY. The application can try calling again with larger buffers.

## Remarks

When using alternate glyphs, the application first reshapes the original glyph without applying any feature tag, then selects an alternate. The original glyph is established as the base glyph. If another alternate is required, the original glyph provides information to match with the corresponding alternates list.

If an alternate glyph is used as the base glyph, no matching output list is found. The user interface uses the selected final form without providing the capability to choose another alternate.

The operations of **ScriptGetFontAlternateGlyphs** can be emulated by [ScriptSubstituteSingleGlyph](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptsubstitutesingleglyph). The application should try parameters one by one while glyphs are substituted.

For shaping fonts with Uniscribe, [ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype) is preferred over the older [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) function.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype)

[ScriptSubstituteSingleGlyph](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptsubstitutesingleglyph)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)