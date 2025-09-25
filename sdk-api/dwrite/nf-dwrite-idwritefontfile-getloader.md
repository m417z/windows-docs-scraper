# IDWriteFontFile::GetLoader

## Description

 Obtains the file loader associated with a font file object.

## Parameters

### `fontFileLoader` [out]

Type: **[IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader)****

When this method returns, contains the address of a pointer to the font file loader associated with the font file object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)