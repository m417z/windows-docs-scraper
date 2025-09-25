# ScriptPlaceOpenType function

## Description

Generates [glyphs](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) and visual attributes for a Unicode run with OpenType information from the output of [ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype).

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, out]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This structures identifies the shaping engine that governs the generated list of glyphs and their associated widths, and x and y placement offsets.

Alternatively, the application can set this parameter to **NULL** to receive unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure containing the OpenType script tag for the writing system to use.

### `tagLangSys` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure containing the OpenType language tag for the writing system.

### `rcRangeChars` [in, optional]

Array of the number of characters in each range. The number of members is indicated in the *cRanges* parameter. The total of values should equal the value of *cChars*.

### `rpRangeProperties` [in, optional]

Array of [TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties) structures defining properties for each range. The number of elements is defined by the *cRanges* parameter.

### `cRanges` [in]

The number of OpenType feature ranges.

### `pwcChars` [in]

Pointer to an array of Unicode characters containing the run. The number of elements is defined by the *cRanges* parameter.

### `pwLogClust` [in]

Pointer to an array of logical cluster information. Each element in the array corresponds to a character in the array defined by *pwcChars*. The value of each element is the offset from the first glyph in the run to the first glyph in the cluster containing the corresponding character. Note that, when the **fRTL** member of the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure is set to **TRUE**, the elements in *pwLogClust* decrease as the array is read.

### `pCharProps` [in]

Pointer to an array of character property values in the Unicode run.

### `cChars` [in]

Number of characters in the Unicode run.

### `pwGlyphs` [in]

Pointer to a glyph buffer obtained from an earlier call to the [ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype) function.

### `pGlyphProps` [in]

Pointer to an array of attributes for each of the glyphs to retrieve. The number of values equals the value of
*cGlyphs*. Since there is one glyph property per glyph, this parameter has the number of elements indicated by *cGlyphs*.

### `cGlyphs` [in]

Count of glyphs in a glyph array buffer.

### `piAdvance` [out]

Pointer to an array, of length indicated by *cGlyphs*, in which this function retrieves [advance width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) information.

### `pGoffset` [out]

Pointer to an array of [GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset) structures in which this structure retrieves the x and y offsets of combining glyphs. This array must be of length indicated by *cGlyphs*.

### `pABC` [out, optional]

Pointer to an [ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc) structure in which this function retrieves the [ABC width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) for the entire [run](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary).

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. In all error cases, the output values are undefined. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

The function returns E_OUTOFMEMORY if the output buffer length indicated by *cGlyphs* is too small. The application can try calling again with larger buffers.

The function returns E_PENDING if the script cache specified by the *psc* parameter does not contain enough information to place the glyphs, and the *hdc* parameter is passed as **NULL** so that the function is unable to complete the placement process. The application should set up a correct device context for the run, and call this function again with the appropriate value in *hdc* and with all other parameters the same.

## Remarks

This function is preferred over the older [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace) function. Some advantages of **ScriptPlaceOpenType** include the following:

* Parameters directly correspond to OpenType tags in font layout tables.
* Parameters define features applied to each character. Input is divided into ranges, and each range has OpenType properties associated with it.

The composite ABC width for the whole item identifies how much the glyphs [overhang](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) to the left of the start position and to the right of the length implied by the sum of the advance widths. The total advance width of the line is exactly abcA+abcB+abcC. The abcA and abcC values are maintained as proportions of the cell height represented in 8 bits and are thus roughly +/-1 percent. The total width retrieved, which is the sum of the abcA+abcB+abcC values indicated by *piAdvance*, is accurate to the resolution of the TrueType shaping engine.

All arrays are in visual order unless the **fLogicalOrder** member is set in the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure indicated by the *psa* parameter.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[SCRIPT_CHARPROP](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_charprop)

[SCRIPT_GLYPHPROP](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_glyphprop)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace)

[ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype)

[TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)