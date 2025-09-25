## Description

Retrieves all the item indices, filtered by the given properties.

## Parameters

### `properties`

Type: **[DWRITE_FONT_PROPERTY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_property) const \***

List of properties to filter by.

### `propertyCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of properties to filter.

### `selectAnyProperty`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`true` if **GetFilteredFontIndices** should select any property; `false` if it should select the intersection of them all.

### `indices` [out]

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

An ascending array of indices, in the range 0 to [IDwriteFontSet::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset-getfontcount) minus 1.

### `maxIndexCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of indices.

### `actualIndexCount` [out]

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The actual number of indices written or needed, in the range 0 to [IDwriteFontSet::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset-getfontcount) minus 1.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_NOT_SUFFICIENT_BUFFER|The buffer is too small, with *actualIndexCount* set to the needed size. The *actualIndexCount* will always be <= [IDwriteFontSet::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset-getfontcount).|

## Remarks

## See also