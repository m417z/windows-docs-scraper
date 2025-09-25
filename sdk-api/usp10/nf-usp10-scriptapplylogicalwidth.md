# ScriptApplyLogicalWidth function

## Description

Takes an array of advance widths for a [run](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) and generates an array of adjusted advance glyph widths.

## Parameters

### `piDx` [in]

Pointer to an array of [advance widths](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) in logical order, one per code point.

### `cChars` [in]

Count of the logical code points in the run.

### `cGlyphs` [in]

Glyph count.

### `pwLogClust` [in]

Pointer to an array of logical clusters from [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

### `psva` [in]

Pointer to a [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr) structure from [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) and updated by [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

### `piAdvance` [in]

Pointer to an array of glyph advance widths from [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

### `psa` [in]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure from [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize) and updated by [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) and [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

### `pABC` [in, out, optional]

Pointer to the overall [ABC width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) of a run. On input, the parameter should contain the run ABC widths retrieved by [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace). On output, the parameter indicates the ABC width updated to match the new widths.

### `piJustify` [out]

Pointer to an array in which the function retrieves the glyph advance widths. This array is suitable for passing to the *piJustify* parameter of [ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout).

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

This function can be used to reapply logical widths obtained with [ScriptGetLogicalWidths](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetlogicalwidths). It can be useful in situations such as metafiling, for which advance width information must be recorded and reapplied in a font-independent manner, independent of glyph substitutions, such as ligaturization.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[ScriptGetLogicalWidths](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetlogicalwidths)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)