# IDWriteTextAnalyzer::AnalyzeScript

## Description

 Analyzes a text range for script boundaries, reading text attributes
from the source and reporting the Unicode script ID to the sink
callback [SetScript](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalysissink-setscriptanalysis).

## Parameters

### `analysisSource`

Type: **[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)***

A pointer to the source object to analyze.

### `textPosition`

Type: **UINT32**

The starting text position within the source object.

### `textLength`

Type: **UINT32**

The text length to analyze.

### `analysisSink`

Type: **[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)***

A pointer to the sink callback object that receives the text analysis.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)