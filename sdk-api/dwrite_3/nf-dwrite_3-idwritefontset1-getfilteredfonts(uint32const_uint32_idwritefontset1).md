## Description

Retrieves a subset of fonts, filtered by the given indices.

## Parameters

### `indices`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const \***

An array of indices to filter by, in the range 0 to [IDwriteFontSet::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset-getfontcount) minus 1.

### `indexCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of indices.

### `filteredFontSet` [out]

Type: **[IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1)\*\***

The address of a pointer to an [IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1) interface. On successful completion, the function sets the pointer to an object representing the subset of fonts indicated by the given indices, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

The indices can come in any order, meaning that **GetFilteredFonts** can produce a new set with items removed, duplicated, or reordered from the original. If you pass zero indices, then an empty font set is returned.

## See also