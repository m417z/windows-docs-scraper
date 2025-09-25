# IDWriteFactory::GetGdiInterop

## Description

 Creates an object that is used for interoperability with GDI.

## Parameters

### `gdiInterop` [out]

Type: **[IDWriteGdiInterop](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritegdiinterop)****

When this method returns, contains an address of a pointer to a GDI interop object if successful, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)