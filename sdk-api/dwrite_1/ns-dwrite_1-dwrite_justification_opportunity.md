# DWRITE_JUSTIFICATION_OPPORTUNITY structure

## Description

The **DWRITE_JUSTIFICATION_OPPORTUNITY** structure specifies justification info per glyph.

## Members

### `expansionMinimum`

Minimum amount of expansion to apply to the side of the glyph. This might vary from zero to infinity, typically being zero except for kashida.

### `expansionMaximum`

Maximum amount of expansion to apply to the side of the glyph. This might vary from zero to infinity, being zero for fixed-size characters and connected scripts, and non-zero for discrete scripts, and non-zero for cursive scripts at expansion points.

### `compressionMaximum`

Maximum amount of compression to apply to the side of the glyph. This might vary from zero up to the glyph cluster size.

### `expansionPriority`

Priority of this expansion point. Larger priorities are applied later, while priority zero does nothing.

### `compressionPriority`

Priority of this compression point. Larger priorities are applied later, while priority zero does nothing.

### `allowResidualExpansion`

Allow this expansion point to use up any remaining slack space even after all expansion priorities have been used up.

### `allowResidualCompression`

Allow this compression point to use up any remaining space even after all compression priorities have been used up.

### `applyToLeadingEdge`

Apply expansion and compression to the leading edge of the glyph. This bit is **FALSE** (0) for connected scripts, fixed-size characters, and diacritics. It is generally **FALSE** within a multi-glyph cluster, unless the script allows expansion of glyphs within a cluster, like Thai.

### `applyToTrailingEdge`

Apply expansion and compression to the trailing edge of the glyph. This bit is **FALSE** (0) for connected scripts, fixed-size characters, and diacritics. It is generally **FALSE** within a multi-glyph cluster, unless the script allows expansion of glyphs within a cluster, like Thai.

### `reserved`

Reserved

## See also

[IDWriteTextAnalyzer1::GetJustificationOpportunities](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getjustificationopportunities)

[IDWriteTextAnalyzer1::JustifyGlyphAdvances](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-justifyglyphadvances)