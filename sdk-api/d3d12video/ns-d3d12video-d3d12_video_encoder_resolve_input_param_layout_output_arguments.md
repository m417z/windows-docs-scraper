## Description

Describes output arguments for [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Members

### `pOpaqueLayoutBuffer`

Pointer to an ID3D12Resource containing the resolved output in hardware-specific layout. This allocation is owned by the app and must be allocated according to the value reported in [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolve_input_param_layout).MaxResolvedBufferAllocationSize for the input argument being resolved.

## Remarks

## See also