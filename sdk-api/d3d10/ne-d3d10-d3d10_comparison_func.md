# D3D10_COMPARISON_FUNC enumeration

## Description

Comparison options.

## Constants

### `D3D10_COMPARISON_NEVER:1`

Never pass the comparison.

### `D3D10_COMPARISON_LESS:2`

If the source data is less than the destination data, the comparison passes.

### `D3D10_COMPARISON_EQUAL:3`

If the source data is equal to the destination data, the comparison passes.

### `D3D10_COMPARISON_LESS_EQUAL:4`

If the source data is less than or equal to the destination data, the comparison passes.

### `D3D10_COMPARISON_GREATER:5`

If the source data is greater than the destination data, the comparison passes.

### `D3D10_COMPARISON_NOT_EQUAL:6`

If the source data is not equal to the destination data, the comparison passes.

### `D3D10_COMPARISON_GREATER_EQUAL:7`

If the source data is greater than or equal to the destination data, the comparison passes.

### `D3D10_COMPARISON_ALWAYS:8`

Always pass the comparison.

## Remarks

A comparison option determines whether how the runtime compares source (new) data against destination (existing) data before storing the new data. The comparison option is declared in a description before an object is created. The API allows you to set a comparison option for a depth-stencil buffer (see [D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc)), depth-stencil operations (see [D3D10_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencilop_desc)), or sampler state (see [D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc)).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)