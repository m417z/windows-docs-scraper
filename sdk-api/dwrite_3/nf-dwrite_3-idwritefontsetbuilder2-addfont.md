## Description

Adds a font to the set being built, with the caller supplying enough information to search on and determine axis ranges, avoiding the need to open the potentially non-local font.

## Parameters

### `fontFile`

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)\***

Font file reference object to add to the set.

### `fontFaceIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The zero-based index of a font face in a collection.

### `fontSimulations`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Font face simulation flags for algorithmic emboldening and italicization.

### `fontAxisValues`

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const \***

A pointer to an array containing a list of font axis values. The array should be the size (the number of elements) indicated by the *fontAxisValueCount* argument.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of font axis values contained in the *fontAxisValues* array.

### `fontAxisRanges`

Type: **[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range) const \***

List of axis ranges.

### `fontAxisRangeCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of axis ranges.

### `properties`

Type: **[DWRITE_FONT_PROPERTY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_property) const \***

List of properties to associate with the reference.

### `propertyCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of properties defined.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

The font properties should include at least a family (typographic or weight/style/stretch). Otherwise the font would be accessible in the **IDWriteFontSet** only by index, not name.

## See also