# IWICDdsFrameDecode::GetFormatInfo

## Description

Gets information about the format in which the DDS image is stored.

## Parameters

### `pFormatInfo` [out]

Type: **[WICDdsFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsformatinfo)***

Information about the DDS format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This information can be used for allocating memory or constructing Direct3D or Direct2D resources, for example by using [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d) or [ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1devicecontext-createbitmap-overload).

## See also

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createbitmap)

[ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d)

[IWICDdsFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsframedecode)

[WICDdsFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsformatinfo)