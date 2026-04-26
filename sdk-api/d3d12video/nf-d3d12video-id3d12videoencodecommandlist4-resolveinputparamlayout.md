## Description

Converts from the hardware-agnostic input layouts of the maps defined in this API into the hardware-specific opaque layouts.

## Parameters

### `pInputArguments`

A [D3D12_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_input_param_layout_input_arguments) specifying the input data to resolve.

### `pOutputArguments`

A [D3D12_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_input_param_layout_output_arguments) specifying the output buffer for the resolved opaque layout.

## Remarks

Input resources must be in **D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ** and output resources in **D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE** before executing this command.

## See also