# IDWriteTextAnalyzer::AnalyzeBidi

## Description

 Analyzes a text range for script directionality, reading attributes
from the source and reporting levels to the sink callback [SetBidiLevel](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalysissink-setbidilevel).

## Parameters

### `analysisSource`

Type: **[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)***

A pointer to a source object to analyze.

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

## Remarks

 While the function can handle multiple paragraphs, the text range
should not arbitrarily split the middle of paragraphs. Otherwise, the
returned levels may be wrong, because the Bidi algorithm is meant to
apply to the paragraph as a whole.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)