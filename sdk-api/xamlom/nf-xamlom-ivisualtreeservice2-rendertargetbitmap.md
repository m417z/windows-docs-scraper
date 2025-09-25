# IVisualTreeService2::RenderTargetBitmap

## Description

Returns an image that represents the object described by handle, or
returns an error if the object does not have or cannot provide
such an image.

## Parameters

### `handle` [in]

The handle associated with the visual for which the caller is requesting a bitmap.

### `options` [in]

A flag that specifies whether only the texture associated with the visual should be rendered, or whether the texture and its children should be rendered.

### `maxPixelWidth` [in]

The maximum width, in pixels, of the returned bitmap.

### `maxPixelHeight` [in]

The maximum height, in pixels, of the returned bitmap.

### `ppBitmapData` [out]

The structure containing the requested bitmap information as well as information pertaining to that bitmap.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. *ppBitmapData* will be set to an [IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata) containing an image. |
| **E_FAIL** | The image could not be acquired or converted. *ppBitmapData* will be set to **NULL**. |
| **E_INVALIDARG** | *handle* does not refer to an object that can return an image, the *options* value is invalid, or *ppBitmapData* is **NULL**. |

## Remarks

The returned image will have

* Format: **DXGI_FORMAT_B8G8R8A8_UNORM**
* AlphaMode: **DXGI_ALPHA_MODE_PREMULTIPLIED**

If the requested bitmap falls within the max pixel width and max pixel height specified, then the bitmap will be returned in its original size. If the size of the image is larger than either one of the two max values specified, then, before the bitmap is returned, the bitmap will be uniformly scaled down until its dimensions fall within the boundaries of the *maxPixelWidth* and *maxPixelHeight* specified.

## See also

[IVisualTreeService2](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservice2)