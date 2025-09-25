# D3D11_BUFFER_UAV structure

## Description

Describes the elements in a buffer to use in a unordered-access view.

## Members

### `FirstElement`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the first element to be accessed.

### `NumElements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the resource. For structured buffers, this is the number of structures in the buffer.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

View options for the resource (see [D3D11_BUFFER_UAV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag)).

## Remarks

This structure is used by a [D3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_unordered_access_view_desc).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)