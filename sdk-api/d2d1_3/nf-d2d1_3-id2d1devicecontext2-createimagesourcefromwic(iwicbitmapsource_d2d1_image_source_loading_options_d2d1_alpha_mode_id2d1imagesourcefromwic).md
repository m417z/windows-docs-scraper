# ID2D1DeviceContext2::CreateImageSourceFromWic

## Description

Creates an image source object from a WIC bitmap source, while populating all pixel memory within the image source.
The image is loaded and stored while using a minimal amount of memory.

## Parameters

### `wicBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The WIC bitmap source to create the image source from.

### `loadingOptions`

Type: **[D2D1_IMAGE_SOURCE_LOADING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_image_source_loading_options)**

Options for creating the image source. Default options are used if NULL.

### `alphaMode`

Type: **[D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode)**

The alpha mode of the image; this is determined automatically from the source’s pixel format if D2D1_ALPHA_MODE_UNKNOWN is passed.

### `imageSource` [out]

Type: **[ID2D1ImageSourceFromWic](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1imagesourcefromwic)****

Receives the new image source instance.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## Remarks

This method creates an image source which can be used to draw the image.

This method supports images that exceed the maximum texture size. Large images are internally stored within a sparse tile cache.

This API supports the same set of pixel formats and alpha modes supported by [CreateBitmapFromWicBitmap](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1devicecontext-createbitmapfromwicbitmap-overload).
If the GPU does not support a given pixel format,
this method will return D2DERR_UNSUPPORTED_PIXEL_FORMAT. This method does not apply adjustments such as gamma or
alpha premultiplication which affect the appearance of the image.

The alphaMode parameter must not be set to D2D1_ALPHA_MODE_STRAIGHT. This method fails if the WIC source uses a
pixel format with straight alpha, unless the alpha mode is
overridden by setting the alphaMode parameter to D2D1_ALPHA_MODE_PREMULTIPLIED or D2D1_ALPHA_MODE_IGNORE.

If the format of the source has an alpha channel, then D2D1_ALPHA_MODE_IGNORE must be passed.
If D2D1_ALPHA_MODE_IGNORE is passed and the format of the source does have an alpha
channel, the alpha channel will be ignored.

This method automatically selects an appropriate storage format to minimize GPU memory usage,
such as using separate luminance and chrominance textures for JPEG images.

If the loadingOptions argument is NULL, D2D uses D2D1_IMAGE_SOURCE_LOADING_OPTIONS_NONE.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)