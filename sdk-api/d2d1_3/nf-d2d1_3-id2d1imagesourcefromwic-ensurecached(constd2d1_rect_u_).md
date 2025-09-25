# ID2D1ImageSourceFromWic::EnsureCached(const D2D1_RECT_U &)

## Description

Ensures that a specified region of the image source cache is populated.
This method can be used to minimize glitches by performing expensive work to populate caches outside of a rendering loop.
This method can also be used to speculatively load image data before it is needed by drawing routines.

## Parameters

### `rectangleToFill` [ref]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-u)**

Specifies the region of the image, in pixels, that should be populated in the cache. By default, this is the entire extent of the image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This API loads image data into caches of image sources, if that data was not already cached. It does not trim pre-existing caches, if any.
More areas within the cache can be populated than actually requested.

The provided region must be constructed to include the scale with which the image source will subsequently be drawn.
These coordinates must be provided in local coordinates.
This means that they must be adjusted prior to calling the API according to the DPI and other relevant transforms,
which can include the world transform and brush transforms.

This operation is only supported when the image source has been initialized using the D2D1_IMAGE_SOURCE_LOADING_OPTIONS_CACHE_ON_DEMAND option.

## See also

[ID2D1ImageSourceFromWic](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesourcefromwic)