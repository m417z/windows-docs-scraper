# IDWriteFontFileLoader::CreateStreamFromKey

## Description

 Creates a font file stream object that encapsulates an open file resource.

## Parameters

### `fontFileReferenceKey` [in]

Type: **const void***

A pointer to a font file reference key that uniquely identifies the font file resource
within the scope of the font loader being used. The buffer allocated for this key must at least be the size, in bytes, specified by  *fontFileReferenceKeySize*.

### `fontFileReferenceKeySize`

Type: **UINT32**

The size of font file reference key, in bytes.

### `fontFileStream` [out]

Type: **[IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream)****

When this method returns, contains the address of a pointer to the newly created [IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The resource is closed when the last reference to *fontFileStream* is released.

## See also

[IDWriteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfileloader)