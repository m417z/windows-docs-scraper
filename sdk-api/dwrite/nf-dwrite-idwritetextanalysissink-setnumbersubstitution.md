# IDWriteTextAnalysisSink::SetNumberSubstitution

## Description

Sets the number substitution on the text range affected by the text analysis.

## Parameters

### `textPosition`

Type: **UINT32**

The starting position from which to report.

### `textLength`

Type: **UINT32**

The number of UTF16 units of the reported range.

### `numberSubstitution`

Type: **[IDWriteNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritenumbersubstitution)***

An object that holds the appropriate digits and numeric punctuation for a given locale. Use [IDWriteFactory::CreateNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createnumbersubstitution) to create this object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextAnalysisSink](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissink)