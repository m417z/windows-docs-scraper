# IDWriteTextAnalysisSink::SetScriptAnalysis

## Description

Reports script analysis for the specified text range.

## Parameters

### `textPosition`

Type: **UINT32**

The starting position from which to report.

### `textLength`

Type: **UINT32**

The number of UTF16 units of the reported range.

### `scriptAnalysis`

Type: **const [DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)***

A pointer to a structure that contains a zero-based index representation of a writing system script and a value indicating whether additional shaping of text is required.

## Return value

Type: **HRESULT**

A successful code or error code to stop analysis.

## See also

[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)