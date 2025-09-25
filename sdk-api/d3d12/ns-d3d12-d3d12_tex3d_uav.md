# D3D12_TEX3D_UAV structure

## Description

Describes a unordered-access 3D texture resource.

## Members

### `MipSlice`

The mipmap slice index.

### `FirstWSlice`

The zero-based index of the first depth slice to be accessed.

### `WSize`

The number of depth slices.

Set to -1 to indicate all the depth slices from **FirstWSlice** to the last slice.

## Remarks

Use this structure with a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure to view the resource as a 3D texture.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)