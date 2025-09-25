# IDWriteLocalFontFileLoader::GetFilePathLengthFromKey

## Description

Obtains the length of the absolute file path from the font file reference key.

## Parameters

### `fontFileReferenceKey` [in]

Type: **const void***

Font file reference key that uniquely identifies the local font file
within the scope of the font loader being used.

### `fontFileReferenceKeySize`

Type: **UINT32**

Size of font file reference key in bytes.

### `filePathLength` [out]

Type: **UINT32***

Length of the file path string, not including the terminated **NULL** character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteLocalFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalfontfileloader)