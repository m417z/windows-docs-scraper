# D3D11_DSV_FLAG enumeration

## Description

Depth-stencil view options.

## Constants

### `D3D11_DSV_READ_ONLY_DEPTH:0x1L`

Indicates that depth values are read only.

### `D3D11_DSV_READ_ONLY_STENCIL:0x2L`

Indicates that stencil values are read only.

## Remarks

This enumeration is used by [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc).

Limiting a depth-stencil buffer to read-only access allows more than one depth-stencil view to be bound to the pipeline simultaneously, since it is not possible to have a read/write conflicts between separate views.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)