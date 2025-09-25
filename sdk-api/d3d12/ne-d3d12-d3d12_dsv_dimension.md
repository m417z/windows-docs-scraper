# D3D12_DSV_DIMENSION enumeration

## Description

Specifies how to access a resource used in a depth-stencil view.

## Constants

### `D3D12_DSV_DIMENSION_UNKNOWN:0`

**D3D12_DSV_DIMENSION_UNKNOWN** is not a valid value for [D3D12_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_view_desc) and is not used.

### `D3D12_DSV_DIMENSION_TEXTURE1D:1`

The resource will be accessed as a 1D texture.

### `D3D12_DSV_DIMENSION_TEXTURE1DARRAY:2`

The resource will be accessed as an array of 1D textures.

### `D3D12_DSV_DIMENSION_TEXTURE2D:3`

The resource will be accessed as a 2D texture.

### `D3D12_DSV_DIMENSION_TEXTURE2DARRAY:4`

The resource will be accessed as an array of 2D textures.

### `D3D12_DSV_DIMENSION_TEXTURE2DMS:5`

The resource will be accessed as a 2D texture with multi sampling.

### `D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:6`

The resource will be accessed as an array of 2D textures with multi sampling.

## Remarks

Specify one of the values in this enumeration in the **ViewDimension** member of a [D3D12_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_view_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)