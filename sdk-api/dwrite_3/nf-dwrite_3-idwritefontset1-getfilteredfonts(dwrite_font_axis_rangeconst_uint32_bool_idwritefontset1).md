## Description

Retrieves a subset of fonts filtered by the given ranges, endpoint-inclusive.

## Parameters

### `fontAxisRanges`

Type: **[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range) const \***

List of axis value ranges to filter by.

### `fontAxisRangeCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of axis value ranges to filter.

### `selectAnyRange`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`true` if **GetFilteredFonts** should select any range; `false` if it should select the intersection of them all.

### `filteredFontSet` [out]

Type: **[IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1)\*\***

The address of a pointer to an [IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1) interface. On successful completion, the function sets the pointer to an object representing the subset of fonts that fall within the ranges, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

If no fonts match the filter, then the returned subset object will be empty (calling [IDWriteFontSet::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontset-getfontcount) on it returns 0), but the function does not return an error. The subset is always equal to or less than the original set.

## See also