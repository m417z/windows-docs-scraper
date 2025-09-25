# IDWriteFontFamily::GetFirstMatchingFont

## Description

 Gets the font that best matches the specified properties.

## Parameters

### `weight`

Type: **[DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight)**

A value that is used to match a requested font weight.

### `stretch`

Type: **[DWRITE_FONT_STRETCH](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_stretch)**

A value that is used to match a requested font stretch.

### `style`

Type: **[DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style)**

A value that is used to match a requested font style.

### `matchingFont` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

When this method returns, contains the address of a pointer to the newly created [IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFamily](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfamily)