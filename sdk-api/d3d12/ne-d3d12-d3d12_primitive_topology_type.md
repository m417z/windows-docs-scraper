# D3D12_PRIMITIVE_TOPOLOGY_TYPE enumeration

## Description

Specifies how the pipeline interprets geometry or hull shader input primitives.

## Constants

### `D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED:0`

The shader has not been initialized with an input primitive type.

### `D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT:1`

Interpret the input primitive as a point.

### `D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE:2`

Interpret the input primitive as a line.

### `D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE:3`

Interpret the input primitive as a triangle.

### `D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH:4`

Interpret the input primitive as a control point patch.

## Remarks

This enum is used by the [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)