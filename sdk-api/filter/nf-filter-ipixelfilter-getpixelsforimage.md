## Description

Implemented by a search filter to supply pixel data for the image being indexed.

## Parameters

### `scalingFactor` [in]

A FLOAT specifying the scaling factor with which the image should be scaled before populating *pixelBuffer*.

### `sourceRect` [in]

A RECT specifying the region of the image for which pixels values should be included in *pixelBuffer*. If this value is nullptr, the entire image should be included.

### `pixelBufferSize` [in]

The expected size of *pixelBuffer*, in bytes.

### `pixelBuffer` [out]

The buffer containing the requested pixel values. This buffer is client-managed and must have the size specified in *pixelBufferSize*.

## Return value

This method can return one of these values.

| Return code | Description |
|-------------|-------------|
| S_OK | Success |

## Remarks

The image data returned in *pixelBuffer* must be in the [IMAGE_PIXELFORMAT](https://learn.microsoft.com/windows/win32/api/filter/ne-filter-image_pixelformat) format specified in the **Format** field of the [IMAGE_INFO](https://learn.microsoft.com/windows/win32/api/filter/ns-filter-image_info) structure returned from the filter's implementation of [IPixelFilter::GetImageInfo](https://learn.microsoft.com/windows/win32/api/filter/nf-filter-ipixelfilter-getimageinfo).

## See also