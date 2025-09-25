# IDWriteLocalFontFileLoader::GetFilePathFromKey

## Description

Obtains the absolute font file path from the font file reference key.

## Parameters

### `fontFileReferenceKey` [in]

Type: **const void***

The font file reference key that uniquely identifies the local font file
within the scope of the font loader being used.

### `fontFileReferenceKeySize`

Type: **UINT32**

The size of font file reference key in bytes.

### `filePath` [out]

Type: **WCHAR***

The character array that receives the local file path.

### `filePathSize`

Type: **UINT32**

The length of the file path character array.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteLocalFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalfontfileloader)