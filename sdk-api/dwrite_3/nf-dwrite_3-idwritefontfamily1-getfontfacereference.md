# IDWriteFontFamily1::GetFontFaceReference

## Description

Gets a font face reference given its zero-based index.

## Parameters

### `listIndex` [in]

Type: **UINT32**

Zero-based index of the font in the font list.

### `fontFaceReference` [out]

Type: **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)****

A pointer to a memory block that receives a pointer to a [IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference) interface for the newly created font face reference object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFamily1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfamily1)