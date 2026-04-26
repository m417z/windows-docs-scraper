## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is D3D12_FEATURE_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT. Reports support for [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, indicates which physical adapter of the device this operation applies to.

### `SessionInfo`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_session_info) containing information pertaining to the encoding session.

### `MapType`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_type) specifying the type of input map.

### `IsSupported`

Output parameter. Indicates if the given input params for feature are supported.

### `MaxResolvedBufferAllocationSize`

Output parameter. Indicates the size of the allocation the user must make for the output opaque buffer result of the ResolveInputParamLayout operation.

## Remarks

## See also