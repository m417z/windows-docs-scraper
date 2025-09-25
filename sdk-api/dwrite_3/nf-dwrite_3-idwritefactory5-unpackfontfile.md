# IDWriteFactory5::UnpackFontFile

## Description

The UnpackFontFile method unpacks font data from a container file (WOFF or WOFF2) and returns the unpacked font data in the form of a font file stream.

## Parameters

### `containerType`

Type: **[DWRITE_CONTAINER_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_container_type)**

Container type returned by AnalyzeContainerType.

### `fileData` [in]

Type: **void**

Pointer to the compressed data.

### `fileDataSize`

Type: **UINT32**

Size of the compressed data, in bytes.

### `unpackedFontStream` [out]

Type: **[IDWriteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfilestream)****

Receives a pointer to a newly created font file stream containing the uncompressed data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Standard HRESULT error code. The return value is E_INVALIDARG if the container type is DWRITE_CONTAINER_TYPE_UNKNOWN.

## See also

[IDWriteFactory5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory5)