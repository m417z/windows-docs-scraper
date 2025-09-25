# IWICDdsDecoder::GetFrame

## Description

Retrieves the specified frame of the DDS image.

## Parameters

### `arrayIndex` [in]

Type: **UINT**

The requested index within the texture array.

### `mipLevel` [in]

Type: **UINT**

The requested mip level.

### `sliceIndex` [in]

Type: **UINT**

The requested slice within the 3D texture.

### `ppIBitmapFrame` [out]

Type: **[IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode)****

A pointer to a [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A DDS file can contain multiple images that are organized into a three level hierarchy. First, DDS file may contain multiple textures in a texture array. Second, each texture can have multiple mip levels. Finally, the texture may be a 3D (volume) texture and have multiple slices, each of which is a 2D texture. See the [DDS documentation](https://learn.microsoft.com/windows/desktop/direct3ddds/dx-graphics-dds) for more information.

WIC maps this three level hierarchy into a linear array of [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode), accessible via [IWICBitmapDecoder::GetFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapdecoder-getframe). However, determining which frame corresponds to a triad of *arrayIndex*, *mipLevel*, and *sliceIndex* value is not trivial because each mip level of a 3D texture has a different depth (number of slices). This method provides additional convenience over **IWICBitmapDecoder::GetFrame** for DDS images by calculating the correct frame given the three indices.

## See also

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createbitmap)

[ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d)

[IWICDdsDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsdecoder)

[WICDdsFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsformatinfo)