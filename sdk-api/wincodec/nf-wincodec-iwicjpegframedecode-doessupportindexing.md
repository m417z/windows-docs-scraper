# IWICJpegFrameDecode::DoesSupportIndexing

## Description

Retrieves a value indicating whether this decoder supports indexing for efficient random access.

## Parameters

### `pfIndexingSupported`

Type: **BOOL***

True if indexing is supported; otherwise, false.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## Remarks

Indexing is only supported for some JPEG types. Call this method

## See also

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)