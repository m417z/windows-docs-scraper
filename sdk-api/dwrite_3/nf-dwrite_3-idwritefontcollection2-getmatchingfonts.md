## Description

Retrieves a list of fonts in the specified font family, ranked in order of how well they match the specified axis values.

## Parameters

### `familyName`

Type: **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const \***

Name of the font family. The name is not case-sensitive, but must otherwise exactly match a family name in the collection.

### `fontAxisValues`

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const \***

A pointer to an array containing a list of font axis values. The array should be the size (the number of elements) indicated by the *fontAxisValueCount* argument.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of font axis values contained in the *fontAxisValues* array.

### `fontList` [out]

Type: **[IDWriteFontList2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontlist2)\*\***

The address of a pointer to an [IDWriteFontList2](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontlist2) interface. On successful completion, the function sets the pointer to a newly created font list object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

If no fonts match, an empty list object is returned (calling [IDWriteFontList::GetFontCount](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontlist-getfontcount) on it returns 0), but the function doesn't return an error.

## See also