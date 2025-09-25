# D3D12_BUFFER_RTV structure

## Description

Describes the elements in a buffer resource to use in a render-target view.

## Members

### `FirstElement`

Number of elements between the beginning of the buffer and the first element to access.

### `NumElements`

The total number of elements in the view.

## Remarks

Use this structure with a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure to view the resource as a buffer.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)