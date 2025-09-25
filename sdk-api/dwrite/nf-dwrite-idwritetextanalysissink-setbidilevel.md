# IDWriteTextAnalysisSink::SetBidiLevel

## Description

Sets a bidirectional level on the range, which is called once per run change (either explicit or resolved implicit).

## Parameters

### `textPosition`

Type: **UINT32**

The starting position from which to report.

### `textLength`

Type: **UINT32**

The number of UTF16 units of the reported range.

### `explicitLevel`

Type: **UINT8**

The explicit level from the paragraph reading direction and any embedded control codes RLE/RLO/LRE/LRO/PDF, which is determined before any additional rules.

### `resolvedLevel`

Type: **UINT8**

The final implicit level considering the
explicit level and characters' natural directionality, after all
Bidi rules have been applied.

## Return value

Type: **HRESULT**

A successful code or error code to stop analysis.

## See also

[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)