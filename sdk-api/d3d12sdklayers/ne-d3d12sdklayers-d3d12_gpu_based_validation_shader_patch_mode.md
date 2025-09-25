# D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE enumeration

## Description

Specifies the type of shader patching used by GPU-Based Validation at either the device or command list level.

## Constants

### `D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_NONE:0`

No shader patching is to be done. This will retain the original shader bytecode. Can lead to errors in some of the GPU-Based Validation state tracking as the unpatched shader may still change resource state (see [Common state promotion](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)) but the promotion will be untracked without patching the shader. This can improve performance but no validation will be performed and may also lead to misleading GPU-Based Validation errors. Use this mode very carefully.

### `D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_STATE_TRACKING_ONLY`

Shaders can be patched with resource state tracking code but no validation. This may improve performance but no validation will be performed.

### `D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION`

The default. Shaders are patched with validation code but erroneous instructions will still be executed.

### `D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_GUARDED_VALIDATION`

Shaders are patched with validation code and erroneous instructions are skipped in execution. This can help avoid crashes or device removal.

### `NUM_D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODES`

Unused, simply the count of the number of modes.

## Remarks

This enum is used by the [D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_device_gpu_based_validation_settings) structure.

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)

[Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation)