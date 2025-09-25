## Description

Creates a text format object used for text layout.

## Parameters

### `fontFamilyName`

Type: **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const \***

Name of the font family from the collection.

### `fontCollection`

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)\***

Font collection. Use `nullptr` to indicate the system font collection.

### `fontAxisValues`

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const \***

A pointer to an array containing a list of font axis values. The array should be the size (the number of elements) indicated by the *fontAxisValueCount* argument.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of font axis values contained in the *fontAxisValues* array.

### `fontSize`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Logical size of the font in DIP units.

### `localeName`

Type: **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const \***

Locale name (for example, "ja-JP", "en-US", "ar-EG").

### `textFormat`

Type: **[IDWriteTextFormat3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritetextformat3)\*\***

The address of a pointer to an [IDWriteTextFormat3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritetextformat3) interface. On successful completion, the function sets the pointer to a newly created text format object, otherwise it sets the pointer to `nullptr`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

If *fontCollection* is `nullptr`, then the system font collection is used, grouped by typographic family name ([DWRITE_FONT_FAMILY_MODEL_TYPOGRAPHIC](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_family_model)) without downloadable fonts.

## See also