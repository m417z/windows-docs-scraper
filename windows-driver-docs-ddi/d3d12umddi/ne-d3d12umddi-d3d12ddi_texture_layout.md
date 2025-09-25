# D3D12DDI_TEXTURE_LAYOUT enumeration

## Description

A **D3D12DDI_TEXTURE_LAYOUT** value specifies a texture layout.

## Constants

### `D3D12DDI_TL_UNDEFINED`

The texture layout is undefined, and is likely adapter-dependent.

### `D3D12DDI_TL_ROW_MAJOR`

The texture layout is row major.

### `D3D12DDI_TL_64KB_TILE_UNDEFINED_SWIZZLE`

The texture layout is a 64 KB tile with undefined swizzle.

### `D3D12DDI_TL_64KB_TILE_STANDARD_SWIZZLE`

The texture layout is a 64 KB tile with standard swizzle.

### `D3D12DDI_TL_DEVICE_DEPENDENT_SWIZZLE_0`

The texture layout is a device-dependent swizzle.

## Remarks

See [**D3D12_TEXTURE_LAYOUT**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) for more details about each layout.

## See also

[**D3D12_TEXTURE_LAYOUT**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout)

[**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088)