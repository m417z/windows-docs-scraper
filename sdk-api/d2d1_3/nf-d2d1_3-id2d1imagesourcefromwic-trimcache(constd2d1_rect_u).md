# ID2D1ImageSourceFromWic::TrimCache

## Description

This method trims the populated regions of the image source cache to just the specified rectangle.

## Parameters

### `rectangleToPreserve` [in, optional]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-u)***

Specifies the region of the image, in pixels, which should be preserved in the image source cache.
Regions which are outside of the rectangle are evicted from the cache. By default, this is an empty rectangle,
meaning that the entire image is evicted from the cache.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The provided region must be constructed to include the scale at which the image source will be drawn at. These coordinates must be provided in local coordinates.
This means that they must be adjusted prior to calling the API according to the DPI and other relevant transforms, which can include the world transform and brush transforms.

This method will fail if on-demand caching was not requested when the image source was created.

As with [ID2D1Device::ClearResources](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1device-clearresources), the caller can need to subsequently issue a D3D flush before memory usage is reduced.

This operation is only supported when the image source has been initialized using the D2D1_IMAGE_SOURCE_LOADING_OPTIONS_CACHE_ON_DEMAND option.

## See also

[ID2D1ImageSourceFromWic](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesourcefromwic)