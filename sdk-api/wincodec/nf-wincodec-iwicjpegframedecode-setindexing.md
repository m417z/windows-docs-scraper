# IWICJpegFrameDecode::SetIndexing

## Description

Enables indexing of the JPEG for efficient random access.

## Parameters

### `options`

Type: **[WICJpegIndexingOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicjpegindexingoptions)**

A value specifying whether indexes should be generated immediately or deferred until a future call to [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels).

### `horizontalIntervalSize`

Type: **UINT**

The granularity of the indexing, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK upon successful completion.

## Remarks

This method enables efficient random-access to the image pixels at the expense of memory usage. The amount of memory required for indexing depends on the requested index granularity. Unless **SetIndexing** is called, it is much more efficient to access a JPEG by progressing through its pixels top-down during calls to [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels).

This method will fail if indexing is unsupported on the file. [IWICJpegFrameDecode::DoesSupportIndexing](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-doessupportindexing) should be called to first determine whether indexing is supported. If this method is called multiple times, the final call changes the index granularity to the requested size.

The provided interval size controls horizontal spacing of index entries. This value is internally rounded up according to the JPEG’s MCU (minimum coded unit) size, which is typically either 8 or 16 unscaled pixels. The vertical size of the index interval is always equal to one MCU size.

Indexes can be generated immediately, or during future calls to [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) to reduce redundant decompression work.

## See also

[IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels)

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)

[IWICJpegFrameDecode::ClearIndexing](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-clearindexing)

[IWICJpegFrameDecode::DoesSupportIndexing](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-doessupportindexing)