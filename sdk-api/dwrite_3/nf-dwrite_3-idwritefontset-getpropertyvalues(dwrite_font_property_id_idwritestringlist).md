# IDWriteFontSet::GetPropertyValues(DWRITE_FONT_PROPERTY_ID,IDWriteStringList)

## Description

Returns the property values of a specific font item index.

## Parameters

### `propertyID`

Type: **[DWRITE_FONT_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/dwrite_3/ne-dwrite_3-dwrite_font_property_id)**

Font property of interest.

### `values` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

Receives a pointer to the newly created localized strings object, or nullptr on failure or non-existent property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)