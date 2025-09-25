# IWICBitmapFlipRotator::Initialize

## Description

Initializes the bitmap flip rotator with the provided parameters.

## Parameters

### `pISource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The input bitmap source.

### `options` [in]

Type: **[WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions)**

The [WICBitmapTransformOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaptransformoptions) to flip or rotate the image.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.