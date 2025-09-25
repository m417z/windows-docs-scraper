# IWICBitmapScaler::Initialize

## Description

Initializes the bitmap scaler with the provided parameters.

## Parameters

### `pISource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The input bitmap source.

### `uiWidth` [in]

Type: **UINT**

The destination width.

### `uiHeight` [in]

Type: **UINT**

The destination height.

### `mode` [in]

Type: **[WICBitmapInterpolationMode](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapinterpolationmode)**

The [WICBitmapInterpolationMode](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapinterpolationmode) to use when scaling.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IWICBitmapScaler](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapscaler) can't be initialized multiple times. For example, when scaling every frame in a multi-frame image, a new **IWICBitmapScaler** must be created and initialized for each frame.

#### Examples

For an example using an [IWICBitmapScaler](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapscaler), see the [How to Scale a Bitmap Source](https://learn.microsoft.com/windows/desktop/wic/-wic-bitmapsources-howto-scale) topic.