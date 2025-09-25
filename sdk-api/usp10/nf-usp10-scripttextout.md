# ScriptTextOut function

## Description

Displays text for the specified script shape and place information.

## Parameters

### `hdc` [in]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching). Note that, unlike some other related Uniscribe functions, this function defines the handle as mandatory.

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `x` [in]

Value of the x coordinate of the first glyph.

### `y` [in]

Value of the y coordinate of the first glyph.

### `fuOptions` [in]

Options equivalent to the *fuOptions* parameter of [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta). This parameter can be set to either ETO_CLIPPED or ETO_OPAQUE, to both values, or to neither value.

### `lprc` [in, optional]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the rectangle used to clip the display. The application can set this parameter to **NULL**.

### `psa` [in]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize).

### `pwcReserved` [in]

Reserved; must be set to **NULL**.

### `iReserved` [in]

Reserved; must be 0.

### `pwGlyphs` [in]

Pointer to an array of glyphs obtained from a previous call to [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

### `cGlyphs` [in]

Count of the glyphs in the array indicated by *pwGlyphs*. The maximum number of glyphs is 65,536.

### `piAdvance` [in]

Pointer to an array of advance widths obtained from a previous call to [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

### `piJustify` [in, optional]

Pointer to an array of justified advance widths (cell widths). The application can set this parameter to **NULL**.

### `pGoffset` [in]

Pointer to a [GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset) structure containing the x and y offsets for the combining glyph.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

This function calls the operating system [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function for text display. For more information, see [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe).

All arrays are in display order unless the **fLogicalOrder** member is set in the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure indicated by *psa*.

For any run that is rendered right-to-left and was generated in logical order by forcing the **fLogicalOrder** member of [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis), the application must call [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) (hdc, TA_RIGHT) and give the right-side coordinate before calling **ScriptTextOut**.

The array indicated by *piJustify* provides cell widths for each glyph. When the width of a glyph differs from the unjustified width, specified by *piAdvance*, space is added to or removed from the glyph cell at its trailing edge. The glyph is always aligned with the leading edge of its cell. This rule applies even in visual order.

When a glyph cell is extended, the extra space is usually made up by the addition of white space. However, for Arabic scripts, the extra space is made up by one or more kashida glyphs, unless the extra space is insufficient for the shortest kashida glyph in the font. The width of the shortest kashida is available by calling [ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties).

The application should pass a value for *piJustify* only if the string must be justified by **ScriptTextOut**. Normally, the application should pass **NULL**.

The application should not use **ScriptTextOut** to write to a metafile unless the metafile will be played back without any font substitution, for example, immediately on the same system for scalable page preview. **ScriptTextOut** records glyph numbers in the metafile. Since glyph numbers vary considerably from one font to another, the file is unlikely to play back correctly when different fonts are substituted. For example, when a metafile is played back at a different scale, a [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta) request recorded in the metafile can resolve to a bitmap instead of a TrueType font. Likewise, if the metafile is played back on a different computer, the requested fonts might not be installed. To write complex scripts in a metafile in a font-independent manner, the application should use [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) to write the logical characters directly, so that glyph generation and placement do not occur until the text is played back.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)