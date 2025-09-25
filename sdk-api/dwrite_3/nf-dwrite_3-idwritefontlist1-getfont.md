# IDWriteFontList1::GetFont

## Description

Gets a font given its zero-based index.

## Parameters

### `listIndex` [in]

Type: **UINT32**

Zero-based index of the font in the font list.

### `font` [out]

Type: **[IDWriteFont3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefont3)****

A pointer to a memory block that receives a pointer to a [IDWriteFont3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefont3) interface for the newly created font object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

This method returns **DWRITE_E_REMOTEFONT** if it could not construct a remote font.

## See also

[IDWriteFontList1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontlist1)