# ScriptGetLogicalWidths function

## Description

Converts the glyph [advance widths](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) for a specific font into logical widths.

## Parameters

### `psa` [in]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure.

### `cChars` [in]

Count of the logical code points in the run.

### `cGlyphs` [in]

Count of the glyphs in the run.

### `piGlyphWidth` [in]

Pointer to an array of glyph advance widths.

### `pwLogClust` [in]

Pointer to an array of logical clusters.

### `psva` [in]

Pointer to a [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr) structure defining visual attributes.

### `piDx` [out]

Pointer to an array of logical widths.

## Return value

Currently returns S_OK in all cases.

## Remarks

This function is useful for recording widths in a font-independent manner. It converts the glyph advance widths calculated for a specific font into logical widths, one per code point, in the same order as the code points. If the same string is then displayed on a different device using a different font, the logical widths can be applied by using [ScriptApplyLogicalWidth](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptapplylogicalwidth) to approximate the original placement. This mechanism is useful when implementing print preview. On the preview screen, it is important to match the layout and placement of the final printed result.

**Note** Ligature glyph widths are divided evenly among the characters they represent.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[ScriptApplyLogicalWidth](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptapplylogicalwidth)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)