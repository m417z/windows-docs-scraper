# D3D11_RTV_DIMENSION enumeration

## Description

These flags identify the type of resource that will be viewed as a render target.

## Constants

### `D3D11_RTV_DIMENSION_UNKNOWN:0`

Do not use this value, as it will cause [ID3D11Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrendertargetview) to fail.

### `D3D11_RTV_DIMENSION_BUFFER:1`

The resource will be accessed as a buffer.

### `D3D11_RTV_DIMENSION_TEXTURE1D:2`

The resource will be accessed as a 1D texture.

### `D3D11_RTV_DIMENSION_TEXTURE1DARRAY:3`

The resource will be accessed as an array of 1D textures.

### `D3D11_RTV_DIMENSION_TEXTURE2D:4`

The resource will be accessed as a 2D texture.

### `D3D11_RTV_DIMENSION_TEXTURE2DARRAY:5`

The resource will be accessed as an array of 2D textures.

### `D3D11_RTV_DIMENSION_TEXTURE2DMS:6`

The resource will be accessed as a 2D texture with multisampling.

### `D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY:7`

The resource will be accessed as an array of 2D textures with multisampling.

### `D3D11_RTV_DIMENSION_TEXTURE3D:8`

The resource will be accessed as a 3D texture.

## Remarks

This enumeration is used in [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc) to create a render-target view.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)