# IDWriteFontFallbackBuilder::AddMapping

## Description

Appends a single mapping to the list. Call this once for each additional mapping.

## Parameters

### `ranges`

Type: **[DWRITE_UNICODE_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_unicode_range)***

Unicode ranges that apply to this mapping.

### `rangesCount`

Type: **UINT32**

Number of Unicode ranges.

### `targetFamilyNames` [in]

Type: **const WCHAR****

List of target family name strings.

### `targetFamilyNamesCount`

Type: **UINT32**

Number of target family names.

### `fontCollection` [in, optional]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)**

Optional explicit font collection for this mapping.

### `localeName` [in, optional]

Type: **const WCHAR***

Locale of the context.

### `baseFamilyName` [in, optional]

Type: **const WCHAR***

Base family name to match against, if applicable.

### `scale`

Type: **FLOAT**

Scale factor to multiply the result target font by.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFallbackBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallbackbuilder)