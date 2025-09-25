# IDWriteFont3::CreateFontFace

## Description

Creates a font face object for the font.

## Parameters

### `fontFace` [out]

Type: **[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)****

A pointer to a memory block that receives a pointer to a [IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3) interface for the newly created font face object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

This method returns **DWRITE_E_REMOTEFONT** if it could not construct a remote font.

## See also

[IDWriteFont3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefont3)