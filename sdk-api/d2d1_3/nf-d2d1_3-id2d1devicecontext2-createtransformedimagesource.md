# ID2D1DeviceContext2::CreateTransformedImageSource

## Description

Creates an image source which shares resources with an original.

## Parameters

### `imageSource` [in]

Type: **[ID2D1ImageSource](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesource)***

The original image.

### `properties` [in]

Type: **const [D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_transformed_image_source_properties)***

Properties for the source image.

### `transformedImageSource` [out]

Type: **[ID2D1TransformedImageSource](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1transformedimagesource)****

Receives the new image source.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)