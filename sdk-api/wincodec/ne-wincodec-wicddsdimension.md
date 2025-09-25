# WICDdsDimension enumeration

## Description

Specifies the dimension type of the data contained in DDS image.

## Constants

### `WICDdsTexture1D:0`

DDS image contains a 1-dimensional texture .

### `WICDdsTexture2D:0x1`

DDS image contains a 2-dimensional texture .

### `WICDdsTexture3D:0x2`

DDS image contains a 3-dimensional texture .

### `WICDdsTextureCube:0x3`

The DDS image contains a cube texture represented as an array of 6 faces.

### `WICDDSTEXTURE_FORCE_DWORD:0x7fffffff`

## Remarks

Both **WICDdsTexture2d** and **WICDdsTextureCube** correspond to [D3D11_RESOURCE_DIMENSION_TEXTURE2D](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_dimension). When using [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d), they are distinguished by the flag [D3D11_RESOURCE_MISC_TEXTURECUBE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) in the structure [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc).

## See also

[IWICDdsDecoder::GetParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsdecoder-getparameters)

[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)