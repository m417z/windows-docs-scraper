# IWICImageEncoder::WriteThumbnail

## Description

Encodes the given image as the thumbnail to the given WIC bitmap encoder.

## Parameters

### `pImage` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The Direct2D image that will be encoded.

### `pEncoder` [in]

Type: **[IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)***

The encoder on which the thumbnail is set.

### `pImageParameters` [in]

Type: **const [WICImageParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicimageparameters)***

Additional parameters to control encoding.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You must create the image that you pass in on the same device as in [IWICImagingFactory2::CreateImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory2-createimageencoder). If you don't specify additional parameters in the variable that *pImageParameters* points to, the encoder uses a set of useful defaults. For info about these defaults, see [WICImageParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicimageparameters).

Before you call **WriteThumbnail**, you must set up the [IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) interface for the encoder on which you want to set the thumbnail.

If **WriteThumbnail** fails, it might return E_OUTOFMEMORY, D2DERR_WRONG_RESOURCE_DOMAIN, or other error codes from the encoder.

## See also

[IWICImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimageencoder)

[IWICImagingFactory2::CreateImageEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory2-createimageencoder)

[WICImageParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicimageparameters)