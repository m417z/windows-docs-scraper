# ScriptPositionSingleGlyph function

## Description

Positions a single glyph with a single adjustment using a specified feature provided in the font for OpenType processing. Most often, applications use this function to align a glyph optically at the beginning or end of a line.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This structure identifies the shaping engine, so that the advance widths can be retrieved.

Alternatively, the application can set this parameter to **NULL** to retrieve unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the script tag for shaping.

### `tagLangSys` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the language tag for shaping.

### `tagFeature` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the feature tag to use for shaping the alternate glyph.

### `lParameter` [in]

A flag specifying if single substitution should be applied to the identifier specified in *wGlyphId*. The application sets this parameter to 1 to apply the single substitution feature to the identifier. The application sets the parameter to 0 if the function should not apply the feature.

### `wGlyphId` [in]

The identifier of the original glyph being shaped.

### `iAdvance` [in]

The original glyph advance width.

### `GOffset` [in]

The original glyph offset. Typically, this value is an output of [ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype) or [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

### `piOutAdvance` [out]

Pointer to the location in which this function retrieves the new advance width adjusted for the alternate glyph.

### `pOutGoffset` [out]

Pointer to the location in which this function retrieves the new glyph offset adjusted for the alternate glyph.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

This function positions an individual glyph by adjusting the advance width and/or the offset of the given glyph. The function assumes that the font requires only one adjustment.

A typical use of this function is the slight adjustment of the margin to account for the visual impression made by certain characters. In Latin script, for example, at the beginning of a line it is common to make a slight adjustment to the left for an initial capital (such as "T" or "O") that does not have a vertical line on the left part of the glyph. Although doing this breaks the strict linear margin, the eye perceives the margin as more even.

The following examples demonstrate this effect. The first example shows strict alignment; the next two examples show an adjustment of the initial "T" to the left. The adjustments are by one pixel and two pixels, respectively. The magnified images to the right show how the "T" pushes slightly farther into the left margin in each successive case.

![Illustration showing the same block of text three times, with enlargements of each showing slightly different alignment](https://learn.microsoft.com/windows/win32/api/usp10/images/HAlign.gif)

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)