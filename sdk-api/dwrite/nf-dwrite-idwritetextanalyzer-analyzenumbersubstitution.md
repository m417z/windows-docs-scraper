# IDWriteTextAnalyzer::AnalyzeNumberSubstitution

## Description

 Analyzes a text range for spans where number substitution is applicable,
reading attributes from the source and reporting substitutable ranges
to the sink callback [SetNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalysissink-setnumbersubstitution).

## Parameters

### `analysisSource`

Type: **[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)***

The source object to analyze.

### `textPosition`

Type: **UINT32**

The starting position within the source object.

### `textLength`

Type: **UINT32**

The length to analyze.

### `analysisSink`

Type: **[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)***

A pointer to the sink callback object that receives the text analysis.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Although the function can handle multiple ranges of differing number
substitutions, the text ranges should not arbitrarily split the
middle of numbers. Otherwise, it will treat the numbers separately
and will not translate any intervening punctuation.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)