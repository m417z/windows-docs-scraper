# D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS structure

## Description

Describes per-command-list settings used by GPU-Based Validation.

## Members

### `ShaderPatchMode`

Specifies a [D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_gpu_based_validation_shader_patch_mode) that overrides the default device-level shader patch mode (see [ID3D12DebugDevice1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter)). By default this value is initialized to the *DefaultShaderPatchMode* assigned to the device (see [D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_device_gpu_based_validation_settings).

## Remarks

Point to an object using this structure with the *pData* member of [ID3D12DebugCommandList1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugcommandlist1-setdebugparameter) to configure per-command-list GPU-Based Validation settings.

## See also

[Debug Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-structures)

[SetEnableGPUBasedValidation](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debug1-setenablegpubasedvalidation)

[Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation)