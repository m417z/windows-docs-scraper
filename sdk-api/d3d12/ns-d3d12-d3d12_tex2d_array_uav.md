# D3D12_TEX2D_ARRAY_UAV structure

## Description

Describes an array of unordered-access 2D texture resources.

## Members

### `MipSlice`

The mipmap slice index.

### `FirstArraySlice`

The zero-based index of the first array slice to be accessed.

### `ArraySize`

The number of slices in the array.

### `PlaneSlice`

The index (plane slice number) of the plane to use in an array of textures.

## Remarks

Use this structure with a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure to view the resource as an array of 2D textures.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)