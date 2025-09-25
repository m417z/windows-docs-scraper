# IDWriteTextAnalysisSource::GetLocaleName

## Description

Gets the locale name on the range affected by the text analysis.

## Parameters

### `textPosition`

Type: **UINT32**

The text position to examine.

### `textLength` [out]

Type: **UINT32***

Contains the length of the text being affected by the text analysis up to the next differing locale.

### `localeName` [out]

Type: **const WCHAR****

Contains an address of a pointer to an array of characters which receives the locale name from the text affected by the text analysis. The array of characters is null-terminated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *localeName* pointer must remain valid until the next call or until the analysis returns.

## See also

[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)