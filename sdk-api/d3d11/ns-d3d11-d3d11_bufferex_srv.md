# D3D11_BUFFEREX_SRV structure

## Description

Describes the elements in a raw buffer resource to use in a shader-resource view.

## Members

### `FirstElement`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first element to be accessed by the view.

### `NumElements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the resource.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [D3D11_BUFFEREX_SRV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bufferex_srv_flag)-typed value that identifies view options for the buffer. Currently, the only option is to identify a raw view of the buffer. For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

## Remarks

This structure is used by [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc) to create a raw view of a buffer.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)