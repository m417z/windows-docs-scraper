# IDWriteTextAnalyzer1::AnalyzeVerticalGlyphOrientation

## Description

Analyzes a text range for script orientation, reading text and
attributes from the source and reporting results to the sink callback [SetGlyphOrientation](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalysissink1-setglyphorientation).

## Parameters

### `analysisSource`

Type: **[IDWriteTextAnalysisSource1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalysissource1)***

Source object to analyze.

### `textPosition`

Type: **UINT32**

Starting position within the source object.

### `textLength`

Type: **UINT32**

Length to analyze.

### `analysisSink`

Type: **[IDWriteTextAnalysisSink1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalysissink1)***

Length to analyze.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)