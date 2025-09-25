# DWRITE_SCRIPT_ANALYSIS structure

## Description

Stores the association of text and its writing system script, as well as some display attributes.

## Members

### `script`

Type: **UINT16**

The zero-based index representation of writing system script.

### `shapes`

Type: **[DWRITE_SCRIPT_SHAPES](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_script_shapes)**

A value that indicates additional shaping requirement of text.

## See also

[IDWriteTextAnalyzer::AnalyzeScript](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzescript)