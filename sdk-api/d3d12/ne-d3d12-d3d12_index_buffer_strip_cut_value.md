# D3D12_INDEX_BUFFER_STRIP_CUT_VALUE enumeration

## Description

When using triangle strip primitive topology, vertex positions are interpreted as vertices of a continuous triangle “strip”. There is a special index value that represents the desire to have a discontinuity in the strip, the cut index value. This enum lists the supported cut values.

## Constants

### `D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED:0`

Indicates that there is no cut value.

### `D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF:1`

Indicates that 0xFFFF should be used as the cut value.

### `D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF:2`

Indicates that 0xFFFFFFFF should be used as the cut value.

## Remarks

This enum is used by the [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)