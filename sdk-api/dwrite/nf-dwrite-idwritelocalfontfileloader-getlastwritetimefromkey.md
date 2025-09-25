# IDWriteLocalFontFileLoader::GetLastWriteTimeFromKey

## Description

Obtains the last write time of the file from the font file reference key.

## Parameters

### `fontFileReferenceKey` [in]

Type: **const void***

The font file reference key that uniquely identifies the local font file
within the scope of the font loader being used.

### `fontFileReferenceKeySize`

Type: **UINT32**

The size of font file reference key in bytes.

### `lastWriteTime` [out]

Type: **FILETIME***

The time of the last font file modification.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteLocalFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalfontfileloader)