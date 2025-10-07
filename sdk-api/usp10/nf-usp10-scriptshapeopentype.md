# ScriptShapeOpenType function

## Description

Generates glyphs and visual attributes for a Unicode run with OpenType information. Each run consists of one call to this function.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, out]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). The structure identifies the shaping engine, so that glyphs can be formed correctly.

Alternatively, the application can set this parameter to **NULL** to receive unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the OpenType script tag for the writing system.

### `tagLangSys` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure containing the OpenType language tag for the writing system.

### `rcRangeChars` [in, optional]

Array of characters in each [range](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary). The number of array elements is indicated by *cRanges*. The values of the elements of this array add up to the value of *cChars*.

### `rpRangeProperties` [in, optional]

Array of [TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties) structures, each representing one OpenType feature range. The number of structures is indicated by the *cRanges* parameter. For more information on *rpRangeProperties*, see the Remarks section.

### `cRanges` [in]

The number of OpenType feature ranges.

### `pwcChars` [in]

Pointer to an array of Unicode characters containing the run.

### `cChars` [in]

Number of characters in the Unicode run.

### `cMaxGlyphs` [in]

Maximum number of glyphs to generate.

### `pwLogClust` [out]

Pointer to a buffer in which this function retrieves an array of logical [cluster](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) information. Each array element corresponds to a character in the array of Unicode characters. The value of each element is the offset from the first glyph in the run to the first glyph in the cluster containing the corresponding character. Note that, when the **fRTL** member of the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure is **TRUE**, the elements decrease as the array is read.

### `pCharProps` [out]

Pointer to a buffer in which this function retrieves an array of character property values, of length indicated by *cChars*.

### `pwOutGlyphs` [out]

Pointer to a buffer in which this function retrieves an array of glyphs.

### `pOutGlyphProps` [out]

Pointer to a buffer in which this function retrieves an array of attributes for each of the retrieved glyphs. The length of the values equals the value of *pcGlyphs*. Since one glyph property is indicated per glyph, the value of this parameter indicates the number of elements specified by *cMaxGlyphs*.

### `pcGlyphs` [out]

Pointer to the location in which this function retrieves the number of glyphs indicated in *pwOutGlyphs*.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. In all error cases, the content of all output array values is undefined.

Error returns include:

* E_OUTOFMEMORY. The output buffer length indicated by *cMaxGlyphs* is insufficient.
* E_PENDING. The script cache specified by the *psc* parameter does not contain enough information to shape the string, and the device context has been passed as **NULL** so that the function is unable to complete the shaping process. The application should set up a correct device context for the run and call this function again with the appropriate context value in *hdc* and with all other parameters the same.
* USP_E_SCRIPT_NOT_IN_FONT. The font corresponding to the device context does not support the required script. The application should choose another font, using either [ScriptGetCMap](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetcmap) or another method to select the font.

## Remarks

**ScriptShapeOpenType** is preferred over the older [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) function. Some advantages of the **ScriptShapeOpenType** include the following:

* Parameters directly correspond to OpenType tags in font layout tables.
* Parameters define features applied to each character.
* Input is divided into runs. Each run has OpenType properties and consists of a single call to **ScriptShapeOpenType**.

If this function returns E_OUTOFMEMORY, the application might call **ScriptShapeOpenType** repeatedly, with successively larger output buffers, until a large enough buffer is provided. The number of glyphs generated by a code point varies according to the script and the font. For a simple script, a Unicode code point might generate a single glyph. However, a complex script font might construct characters from components, and thus generate several times as many glyphs as characters. Also, there are special cases, such as invalid character representations, in which extra glyphs are added to represent the invalid sequence. Therefore, a reasonable guess for the size of the buffer indicated by *pwOutGlyphs* is 1.5 times the length of the character buffer, plus an additional 16 glyphs for rare cases, for example, invalid sequence representation.

This function can set the **fNoGlyphIndex** member of the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure if the font or operating system cannot support glyph indexes.

The application can call **ScriptShapeOpenType** to determine if a font supports the characters in a given string. If the function returns S_OK, the application should check the output for missing glyphs. If **fLogicalOrder** is set to **TRUE** in the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure, the function always generates glyphs in the same order as the original Unicode characters. If **fLogicalOrder** is set to **FALSE**, the function generates right-to-left items in reverse order so that [ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout) does not have to reverse them before calling [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta).

If the **eScript** member of [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) is set to SCRIPT_UNDEFINED, shaping is disabled. In this case, **ScriptShapeOpenType** displays the glyph that is in the font cmap table. If no glyph is in the table, the function indicates that glyphs are missing.

**ScriptShapeOpenType** sequences clusters uniformly within the run, and sequences glyphs uniformly within a cluster. It uses the value of the **fRTL** member of [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis), from [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype), to identify if sequencing is left-to-right or right-to-left.

For the *rpRangeProperties* parameter, the [TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties) structure points to an array of [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) structures. This array is used as follows:

* Each element of the array indicated for *rpRangeProperties* describes a range.
* Spans of text sharing particular properties tend to "nest," and nested spans can share [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) information. For example, in the illustration below:
  + The rows of numbers at the top represent ranges, items, and runs, respectively.
  + Each span labeled here with a letter represents a single OpenType feature. The features that fall into each range are stored in the [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) array of that range.
  + For each range, the array of [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) structures corresponds to the letters for the spans that contain that range.
  + In this illustration, range 2 is indirectly associated with the [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) structures for spans A, B, and C. Range 4 is associated only with the structures for spans A and D.

![Illustration showing the range, item, run, and feature of each word in a line of text that uses six properties to present eight words](https://learn.microsoft.com/windows/win32/api/usp10/images/Nested_Properties.GIF)

**Note** The illustration makes use of many calls to **ScriptShapeOpenType**, each representing one run.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

#### Examples

The following example shows how **ScriptShapeOpenType** generates a logical cluster array (*pwLogClust*) from a character array (*pwcChars*) and a glyph array (*pwOutGlyphs*). The run has four clusters.

* First cluster: one character represented by one glyph
* Second cluster: one character represented by three glyphs
* Third cluster: three characters represented by one glyph
* Fourth cluster: two characters represented by three glyphs

The run is described as follows in the character and glyph arrays.

Character array:

* | c1u1 | c2u1 | c3u1 c3u2 c3u3 | c4u1 c4u2 |

Glyph array:

* | c1g1 | c2g1 c2g2 c2g3 | c3g1 | c4g1 c4g2 c4g3 |

Notation for the array elements consists of these items:

* c\<n> means cluster n.
* g\<m> means glyph m.
* u<p> means Unicode code point p.

The generated cluster array stores offsets to the cluster containing the character. Units are expressed in glyphs.

* | 0 | 1 | 4 4 4 | 5 5 |

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout)

[TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)