# D3D12_TEXTURE_COPY_TYPE enumeration

## Description

Specifies what type of texture copy is to take place.

## Constants

### `D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:0`

Indicates a subresource, identified by an index, is to be copied.

### `D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:1`

Indicates a place footprint, identified by a [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) structure, is to be copied.

## Remarks

This enum is used by the [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)