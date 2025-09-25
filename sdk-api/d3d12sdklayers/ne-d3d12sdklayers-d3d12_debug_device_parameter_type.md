# D3D12_DEBUG_DEVICE_PARAMETER_TYPE enumeration

## Description

Specifies the data type of the memory pointed to by the *pData* parameter of [ID3D12DebugDevice1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter) and [ID3D12DebugDevice1::GetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-getdebugparameter).

## Constants

### `D3D12_DEBUG_DEVICE_PARAMETER_FEATURE_FLAGS:0`

Indicates *pData* points to a [D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature) value.

### `D3D12_DEBUG_DEVICE_PARAMETER_GPU_BASED_VALIDATION_SETTINGS`

Indicates *pData* points to a [D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_device_gpu_based_validation_settings) structure.

### `D3D12_DEBUG_DEVICE_PARAMETER_GPU_SLOWDOWN_PERFORMANCE_FACTOR`

Indicates *pData* points to a [D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_device_gpu_slowdown_performance_factor) structure.

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)

[Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation)