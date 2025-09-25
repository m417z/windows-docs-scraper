## Description

Returns a subset of fonts filtered by the given properties.

## Parameters

### `familyName`

The font family name.

### `fontWeight`

The font weight.

### `fontStretch`

The font stretch value.

### `fontStyle`

The font style.

### `filteredSet`

Type: [out] **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)****

The subset of fonts that match the properties, or nullptr on failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If no fonts matched the filter, the subset will be empty (GetFontCount returns 0), but the function does not return an error. The subset will
always be equal to or less than the original set. If you only want to filter out remote fonts, you may pass null in properties and zero in propertyCount.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)