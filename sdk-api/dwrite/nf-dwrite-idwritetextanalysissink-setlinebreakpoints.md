# IDWriteTextAnalysisSink::SetLineBreakpoints

## Description

Sets line-break opportunities for each character, starting from the specified position.

## Parameters

### `textPosition`

Type: **UINT32**

The starting text position from which to report.

### `textLength`

Type: **UINT32**

The number of UTF16 units of the reported range.

### `lineBreakpoints` [in]

Type: **[DWRITE_LINE_BREAKPOINT](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_line_breakpoint)***

A pointer to a structure that contains breaking conditions set for each character from the starting position to the end of the specified range.

## Return value

Type: **HRESULT**

A successful code or error code to stop analysis.

## See also

[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)