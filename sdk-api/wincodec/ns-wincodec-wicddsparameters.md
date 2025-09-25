# WICDdsParameters structure

## Description

Specifies the DDS image dimension, [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and alpha mode of contained data.

## Members

### `Width`

Type: **UINT**

The width, in pixels, of the texture at the largest mip size (mip level 0).

### `Height`

Type: **UINT**

The height, in pixels, of the texture at the largest mip size (mip level 0). When the DDS image contains a 1-dimensional texture, this value is equal to 1.

### `Depth`

Type: **UINT**

The number of slices in the 3D texture. This is equivalent to the depth, in pixels, of the 3D texture at the largest mip size (mip level 0). When the DDS image contains a 1- or 2-dimensional texture, this value is equal to 1.

### `MipLevels`

Type: **UINT**

The number of mip levels contained in the DDS image.

### `ArraySize`

Type: **UINT**

The number of textures in the array in the DDS image.

### `DxgiFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) of the DDS pixel data.

### `Dimension`

Type: **[WICDdsDimension](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicddsdimension)**

Specifies the dimension type of the data contained in DDS image (1D, 2D, 3D or cube texture).

### `AlphaMode`

Type: **[WICDdsAlphaMode](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicddsalphamode)**

Specifies the alpha behavior of the DDS image.

## See also

[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)

[WICDdsAlphaMode](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicddsalphamode)

[WICDdsDimension](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicddsdimension)