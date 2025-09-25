# D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS structure

## Description

Describes settings used by GPU-Based Validation.

## Members

### `MaxMessagesPerCommandList`

Specifies a UINT that limits the number of messages that can be stored in the GPU-Based Validation message log. The default value is 256. Since many identical errors can be produced in a single Draw/Dispatch call it may be useful to increase this number. Note this can become a memory burden if a large number of command lists are used as there is a committed message log per command list.

### `DefaultShaderPatchMode`

Specifies the [D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_gpu_based_validation_shader_patch_mode) that GPU-Based Validation uses when injecting validation code into shaders, except when overridden by per-command-list GPU-Based Validation settings (see [D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_debug_command_list_gpu_based_validation_settings)). The default value is D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION.

### `PipelineStateCreateFlags`

Specifies one of the [D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_gpu_based_validation_pipeline_state_create_flags) that indicates how GPU-Based Validation handles patching pipeline states. The default value is D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE.

## Remarks

Point to an object using this structure with the *pData* member of [ID3D12DebugDevice1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter) to configure device-wide GPU-Based Validation settings.

Individual command lists can override the default shader patch mode using [ID3D12DebugCommandList1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugcommandlist1-setdebugparameter).

## See also

[Debug Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-structures)

[SetEnableGPUBasedValidation](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debug1-setenablegpubasedvalidation)

[Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation)