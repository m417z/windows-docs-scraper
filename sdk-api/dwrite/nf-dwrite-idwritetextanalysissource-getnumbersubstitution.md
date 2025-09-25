# IDWriteTextAnalysisSource::GetNumberSubstitution

## Description

Gets the number substitution from the text range affected by the text analysis.

## Parameters

### `textPosition`

Type: **UINT32**

The starting position from which to report.

### `textLength` [out]

Type: **UINT32***

Contains the length of the text, in characters, remaining in the text range up to the next differing number substitution.

### `numberSubstitution` [out]

Type: **[IDWriteNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritenumbersubstitution)****

Contains an address of a pointer to an object, which was created with [IDWriteFactory::CreateNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createnumbersubstitution), that holds the appropriate digits and numeric punctuation for a given locale.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any implementation should return the number substitution with an incremented reference count, and the analysis will release when finished
with it (either before the next call or before it returns). However,
the sink callback may hold onto it after that.

## See also

[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)