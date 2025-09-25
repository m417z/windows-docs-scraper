# D3D12_RTV_DIMENSION enumeration

## Description

Identifies the type of resource to view as a render target.

## Constants

### `D3D12_RTV_DIMENSION_UNKNOWN:0`

Do not use this value, as it will cause [ID3D12Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrendertargetview) to fail.

### `D3D12_RTV_DIMENSION_BUFFER:1`

The resource will be accessed as a buffer.

### `D3D12_RTV_DIMENSION_TEXTURE1D:2`

The resource will be accessed as a 1D texture.

### `D3D12_RTV_DIMENSION_TEXTURE1DARRAY:3`

The resource will be accessed as an array of 1D textures.

### `D3D12_RTV_DIMENSION_TEXTURE2D:4`

The resource will be accessed as a 2D texture.

### `D3D12_RTV_DIMENSION_TEXTURE2DARRAY:5`

The resource will be accessed as an array of 2D textures.

### `D3D12_RTV_DIMENSION_TEXTURE2DMS:6`

The resource will be accessed as a 2D texture with multisampling.

### `D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:7`

The resource will be accessed as an array of 2D textures with multisampling.

### `D3D12_RTV_DIMENSION_TEXTURE3D:8`

The resource will be accessed as a 3D texture.

## Remarks

Specify one of the values in this enumeration in the **ViewDimension** member of a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)