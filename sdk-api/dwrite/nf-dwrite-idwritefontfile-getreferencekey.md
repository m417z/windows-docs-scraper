# IDWriteFontFile::GetReferenceKey

## Description

 Obtains the pointer to the reference key of a font file. The returned pointer is valid until the font file object is released.

## Parameters

### `fontFileReferenceKey` [out]

Type: **const void****

When this method returns, contains an address of a pointer to the font file reference key. Note that the pointer value is only valid until the font file object it is obtained from is released. This parameter is passed uninitialized.

### `fontFileReferenceKeySize` [out]

Type: **UINT32***

When this method returns, contains the size of the font file reference key in bytes. This parameter is passed uninitialized.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)