## Description

The **DWRITE_PANOSE** union describes typeface classification values that you use with [IDWriteFont1::GetPanose](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefont1-getpanose) to select and match the font.

## Members

### `values`

A 10-byte array of typeface classification values.

### `familyKind`

A [DWRITE_PANOSE_FAMILY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family)-typed value that specifies the typeface classification values to get.

### `text`

The text structure.

### `text.familyKind`

The [DWRITE_PANOSE_FAMILY_TEXT_DISPLAY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family) value (2) that specifies text display typeface classification.

### `text.serifStyle`

A [DWRITE_PANOSE_SERIF_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_serif_style)-typed value that specifies the serif style of text.

### `text.weight`

A [DWRITE_PANOSE_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_weight)-typed value that specifies the weight of the text.

### `text.proportion`

A [DWRITE_PANOSE_PROPORTION](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_proportion)-typed value that specifies the proportion for the text.

### `text.contrast`

A [DWRITE_PANOSE_CONTRAST](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_contrast)-typed value that specifies the contrast for the text.

### `text.strokeVariation`

A [DWRITE_PANOSE_STROKE_VARIATION](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_stroke_variation)-typed value that specifies the stroke variation for the text.

### `text.armStyle`

A [DWRITE_PANOSE_ARM_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_arm_style)-typed value that specifies the arm style of text.

### `text.letterform`

A [DWRITE_PANOSE_LETTERFORM](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_letterform)-typed value that specifies the letter form for the text.

### `text.midline`

A [DWRITE_PANOSE_MIDLINE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_midline)-typed value that specifies the midline for the text.

### `text.xHeight`

A [DWRITE_PANOSE_XHEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_xheight)-typed value that specifies the relative size of lowercase text.

### `script`

The script structure.

### `script.familyKind`

The [DWRITE_PANOSE_FAMILY_SCRIPT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family) value (3) that specifies script typeface classification.

### `script.toolKind`

A [DWRITE_PANOSE_TOOL_KIND](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_tool_kind)-typed value that specifies the kind of tool for the script.

### `script.weight`

A [DWRITE_PANOSE_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_weight)-typed value that specifies the weight of the script.

### `script.spacing`

A [DWRITE_PANOSE_SPACING](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_spacing)-typed value that specifies the spacing of the script.

### `script.aspectRatio`

A [DWRITE_PANOSE_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_aspect_ratio)-typed value that specifies the aspect ratio of the script.

### `script.contrast`

A [DWRITE_PANOSE_CONTRAST](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_contrast)-typed value that specifies the contrast for the script.

### `script.scriptTopology`

A [DWRITE_PANOSE_SCRIPT_TOPOLOGY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_script_topology)-typed value that specifies the script topology.

### `script.scriptForm`

A [DWRITE_PANOSE_SCRIPT_FORM](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_script_form)-typed value that specifies the script form.

### `script.finials`

A [DWRITE_PANOSE_FINIALS](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_finials)-typed value that specifies the script finials.

### `script.xAscent`

A [DWRITE_PANOSE_XASCENT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_xascent)-typed value that specifies the relative size of lowercase letters.

### `decorative`

The decorative structure.

### `decorative.familyKind`

The [DWRITE_PANOSE_FAMILY_DECORATIVE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family) value (4) that specifies decorative typeface classification.

### `decorative.decorativeClass`

A [DWRITE_PANOSE_DECORATIVE_CLASS](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_decorative_class)-typed value that specifies the class of the decorative typeface.

### `decorative.weight`

A [DWRITE_PANOSE_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_weight)-typed value that specifies the weight of the decorative typeface.

### `decorative.aspect`

A [DWRITE_PANOSE_ASPECT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_aspect)-typed value that specifies the aspect of the decorative typeface.

### `decorative.contrast`

A [DWRITE_PANOSE_CONTRAST](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_contrast)-typed value that specifies the contrast for the decorative typeface.

### `decorative.serifVariant`

The serif variant of the decorative typeface.

### `decorative.fill`

A [DWRITE_PANOSE_FILL](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_fill)-typed value that specifies the fill of the decorative typeface.

### `decorative.lining`

A [DWRITE_PANOSE_LINING](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_lining)-typed value that specifies the lining of the decorative typeface.

### `decorative.decorativeTopology`

A [DWRITE_PANOSE_DECORATIVE_TOPOLOGY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_decorative_topology)-typed value that specifies the decorative topology.

### `decorative.characterRange`

A [DWRITE_PANOSE_CHARACTER_RANGES](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_character_ranges)-typed value that specifies the character range of the decorative typeface.

### `symbol`

The symbol structure.

### `symbol.familyKind`

The [DWRITE_PANOSE_FAMILY_SYMBOL](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family) value (5) that specifies symbol typeface classification.

### `symbol.symbolKind`

A [DWRITE_PANOSE_SYMBOL_KIND](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_kind)-typed value that specifies the kind of symbol set.

### `symbol.weight`

A [DWRITE_PANOSE_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_weight)-typed value that specifies the weight of the symbol typeface.

### `symbol.spacing`

A [DWRITE_PANOSE_SPACING](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_spacing)-typed value that specifies the spacing of the symbol typeface.

### `symbol.aspectRatioAndContrast`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio and contrast of the symbol typeface.

### `symbol.aspectRatio94`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio 94 of the symbol typeface.

### `symbol.aspectRatio119`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio 119 of the symbol typeface.

### `symbol.aspectRatio157`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio 157 of the symbol typeface.

### `symbol.aspectRatio163`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio 163 of the symbol typeface.

### `symbol.aspectRatio211`

A [DWRITE_PANOSE_SYMBOL_ASPECT_RATIO](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_symbol_aspect_ratio)-typed value that specifies the aspect ratio 211 of the symbol typeface.

## Remarks

**Note** The **familyKind** member (index 0) is the only stable entry in the 10-byte array because all the entries that follow can change dynamically depending on the context of the first member.

## See also

[DWRITE_PANOSE_FAMILY](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_panose_family)

[IDWriteFont1::GetPanose](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritefont1-getpanose)