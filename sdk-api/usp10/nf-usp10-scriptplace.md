# ScriptPlace function

## Description

Generates glyph [advance width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) and two-dimensional offset information from the output of [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

## Parameters

### `hdc` [in]

Optional. Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `pwGlyphs` [in]

Pointer to a glyph buffer obtained from an earlier call to the [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) function.

### `cGlyphs` [in]

Count of glyphs in the glyph buffer.

### `psva` [in]

Pointer to an array of [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr) structures indicating visual attributes.

### `psa` [in, out]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure. On input, this structure is obtained from a previous call to [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize). On output, this structure contains values retrieved by **ScriptPlace**.

### `piAdvance` [out]

Pointer to an array in which this function retrieves advance width information.

### `pGoffset` [out]

Optional. Pointer to an array of [GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset) structures in which this function retrieves the x and y offsets of combining glyphs. This array must be of length indicated by *cGlyphs*.

### `pABC` [out]

Pointer to an [ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc) structure in which this function retrieves the [ABC width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) for the entire [run](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary).

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

The function returns E_PENDING if the script cache specified by the *psc* parameter does not contain enough information to place the glyphs, and the *hdc* parameter is set to **NULL** so that the function cannot complete the placement process. The application should set up a correct device context for the run, and call this function again with the appropriate device context and with all other parameters the same.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

The composite ABC width for the whole item identifies how much the glyphs [overhang](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) to the left of the start position and to the right of the length implied by the sum of the advance widths. The total advance width of the line is exactly abcA+abcB+abcC. The abcA and abcC values are maintained as proportions of the cell height represented in 8 bits and are thus roughly +/-1 percent. The total width retrieved, which is the sum of the abcA+abcB+abcC values indicated by *piAdvance*, is accurate to the resolution of the TrueType shaping engine.

All arrays are in visual order unless the **fLogicalOrder** member is set in the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure indicated by the *psa* parameter.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[GOFFSET](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-goffset)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)