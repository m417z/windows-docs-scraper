# IDWriteTextAnalyzer::AnalyzeLineBreakpoints

## Description

 Analyzes a text range for potential breakpoint opportunities, reading
attributes from the source and reporting breakpoint opportunities to
the sink callback [SetLineBreakpoints](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalysissink-setlinebreakpoints).

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

## Remarks

 Although the function can handle multiple paragraphs, the text range
should not arbitrarily split the middle of paragraphs, unless the
specified text span is considered a whole unit. Otherwise, the
returned properties for the first and last characters will
inappropriately allow breaks.

## See also

[IDWriteTextAnalyzer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalyzer)