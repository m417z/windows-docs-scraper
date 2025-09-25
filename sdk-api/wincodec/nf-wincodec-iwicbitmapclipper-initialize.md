# IWICBitmapClipper::Initialize

## Description

Initializes the bitmap clipper with the provided parameters.

## Parameters

### `pISource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

he input bitmap source.

### `prc` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The rectangle of the bitmap source to clip.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.