# D3D12_TEX2D_UAV structure

## Description

Describes a unordered-access 2D texture resource.

## Members

### `MipSlice`

The mipmap slice index.

### `PlaneSlice`

The index (plane slice number) of the plane to use in the texture.

## Remarks

Use this structure with a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure to view the resource as a 2D texture.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)