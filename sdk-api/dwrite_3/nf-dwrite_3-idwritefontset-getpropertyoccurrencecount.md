# IDWriteFontSet::GetPropertyOccurrenceCount

## Description

Returns how many times a given property value occurs in the set.

## Parameters

### `property` [in]

Type: **const [DWRITE_FONT_PROPERTY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_property)***

Font property of interest.

### `propertyOccurrenceCount` [out]

Type: **UINT32***

Receives how many times the property occurs.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)