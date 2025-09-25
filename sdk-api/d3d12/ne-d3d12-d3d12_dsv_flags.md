# D3D12_DSV_FLAGS enumeration

## Description

Specifies depth-stencil view options.

## Constants

### `D3D12_DSV_FLAG_NONE:0`

Indicates a default view.

### `D3D12_DSV_FLAG_READ_ONLY_DEPTH:0x1`

Indicates that depth values are read only.

### `D3D12_DSV_FLAG_READ_ONLY_STENCIL:0x2`

Indicates that stencil values are read only.

## Remarks

Specify a combination of the values in this enumeration in the **Flags** member of a [D3D12_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_view_desc) structure.
The values are combined by using a bitwise OR operation.

Limiting a depth-stencil buffer to read-only access allows more than one depth-stencil view to be bound to the pipeline simultaneously, since it is not possible to have read/write conflicts between separate views.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)