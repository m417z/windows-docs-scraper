## Description

Returns all unique property values in the set, which can be used for purposes such as displaying a family list or tag cloud. Values are returned in priority order according to the language list, such that if a font contains more than one localized name, then the preferred one is returned.

## Parameters

### `propertyID`

Type: **[DWRITE_FONT_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/dwrite_3/ne-dwrite_3-dwrite_font_property_id)**

Font property of interest.

### `preferredLocaleNames`

Type: **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const \***

The preferred locale names to query as a list of semicolon-delimited names in preferred order. When a particular string (such as font family) has more than one localized name, then the first match is returned. If the first match doesn't exist, then the second match is returned, and so on. For example, "ja-jp;en-us".

### `values`

Type: \[out\] **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

Receives a pointer to the newly created localized strings object; or `nullptr` on failure or non-existent property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, then it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)