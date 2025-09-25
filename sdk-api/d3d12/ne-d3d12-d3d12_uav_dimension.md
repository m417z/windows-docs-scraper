# D3D12_UAV_DIMENSION enumeration

## Description

Identifies unordered-access view options.

## Constants

### `D3D12_UAV_DIMENSION_UNKNOWN:0`

The view type is unknown.

### `D3D12_UAV_DIMENSION_BUFFER:1`

View the resource as a buffer.

### `D3D12_UAV_DIMENSION_TEXTURE1D:2`

View the resource as a 1D texture.

### `D3D12_UAV_DIMENSION_TEXTURE1DARRAY:3`

View the resource as a 1D texture array.

### `D3D12_UAV_DIMENSION_TEXTURE2D:4`

View the resource as a 2D texture.

### `D3D12_UAV_DIMENSION_TEXTURE2DARRAY:5`

View the resource as a 2D texture array.

### `D3D12_UAV_DIMENSION_TEXTURE3D:8`

View the resource as a 3D texture array.

## Remarks

Specify one of the values in this enumeration in the **ViewDimension** member of a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)