## Description

Implemented by a search filter to provide information about the dimensions and format of the image being indexed.

## Parameters

### `imageInfo` [out]

An [IMAGE_INFO](https://learn.microsoft.com/windows/win32/api/filter/ns-filter-image_info) structure specifying the dimensions and format of the image being indexed.

## Return value

This method can return one of these values.

| Return code | Description |
|-------------|-------------|
| S_OK | Success |
| E_OUTOFMEMORY | Failed to allocate necessary memory. |

## Remarks

The indexer calls **GetImageInfo** first, in order to allocate the necessary buffers for the image. After this method returns, the indexer will call [IPixelFilter::GetPixelsForImage](https://learn.microsoft.com/windows/win32/api/filter/nf-filter-ipixelfilter-getpixelsforimage) one or more times to retrieve the raw image pixels.

## See also