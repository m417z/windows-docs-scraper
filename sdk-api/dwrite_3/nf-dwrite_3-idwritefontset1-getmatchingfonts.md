## Description

Retrieves a matching font set based on the requested inputs, ordered so that nearer matches are earlier.

## Parameters

### `fontProperty`

Type: **[DWRITE_FONT_PROPERTY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_property) const \***

Font property of interest, such as typographic family or weight/stretch/style family.

### `fontAxisValues`

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const \***

A pointer to an array containing a list of font axis values. The array should be the size (the number of elements) indicated by the *fontAxisValueCount* argument.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of font axis values contained in the *fontAxisValues* array.

### `matchingFonts`

Type: **[IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1)\*\***

The address of a pointer to an [IDWriteFontSet1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset1) interface. On successful completion, the function sets the pointer to a prioritized list of fonts that match the properties, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

This method can yield distinct items that were not in the original font set, including items with simulation flags (if they would be a closer match to the request), and instances that were not named by the font author. Items from the same font resources are collapsed into one: the closest possible match.

## See also