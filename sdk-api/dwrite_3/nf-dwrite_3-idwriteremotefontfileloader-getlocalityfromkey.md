# IDWriteRemoteFontFileLoader::GetLocalityFromKey

## Description

Gets the locality of the file resource identified by the unique key.

## Parameters

### `fontFileReferenceKey` [in]

Type: **void**

Font file reference key that uniquely identifies the font file resource within the scope of the font loader being used.

### `fontFileReferenceKeySize`

Type: **UINT32**

Size of font file reference key in bytes.

### `locality` [out]

Type: **[DWRITE_LOCALITY](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_locality)***

Locality of the file.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[IDWriteRemoteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfileloader)