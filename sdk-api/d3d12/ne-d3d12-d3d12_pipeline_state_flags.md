# D3D12_PIPELINE_STATE_FLAGS enumeration

## Description

Flags to control pipeline state.

## Constants

### `D3D12_PIPELINE_STATE_FLAG_NONE:0`

Indicates no flags.

### `D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG:0x1`

Indicates that the pipeline state should be compiled with additional information to assist debugging.
This can only be set on WARP devices.

### `D3D12_PIPELINE_STATE_FLAG_DYNAMIC_DEPTH_BIAS`

Indicates that the pipeline state can be dynamically changed after the pipeline is set by using RSSetDepthBias.

### `D3D12_PIPELINE_STATE_FLAG_DYNAMIC_INDEX_BUFFER_STRIP_CUT`

Indicates that the pipeline state can be dynamically changed after the pipeline is set by using IASetIndexBufferStripCutValue.

## Remarks

This enum is used by the **Flags** member of the
[D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and
[D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structures.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)