# D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS enumeration

## Description

Specifies how GPU-Based Validation handles patched pipeline states during [ID3D12Device::CreateGraphicsPipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-creategraphicspipelinestate) and [ID3D12Device::CreateComputePipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcomputepipelinestate).

## Constants

### `D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE:0`

This is the default value. Indicates no patching of pipeline states should be done during PSO creation. Instead PSO’s are patched on first use in a command list. This can help to reduce the up-front cost of PSO creation but may instead slow down command list recording until a steady-state is reached.

### `D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_TRACKING_ONLY_SHADERS:0x1`

Indicates that state-tracking GPU-Based Validation PSO’s should be created along with the original PSO at create time.

### `D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_UNGUARDED_VALIDATION_SHADERS:0x2`

Indicates that unguarded GPU-Based Validation PSO’s should be created along with the original PSO at create time.

### `D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_GUARDED_VALIDATION_SHADERS:0x4`

Indicates that guarded GPU-Based Validation PSO’s should be created along with the original PSO at create time.

### `D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_VALID_MASK:0x7`

Internal use only.

## Remarks

This enum is used by the [D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_device_gpu_based_validation_settings) structure.

Generally speaking most application developers are likely to leave this parameter unchanged. However, if the overhead of deferring patched PSO creation is suspected to be too much of a performance problem, then developers should consider changing this setting.

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)

[Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation)