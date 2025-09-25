# D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE enumeration

## Description

Specifies the alpha fill mode for video processing. This value is used by the [D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_output_stream_desc) structure.

## Constants

### `D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_OPAQUE`

Alpha values inside the target rectangle are set to opaque.

### `D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_BACKGROUND`

Alpha values inside the target rectangle are set to the alpha value specified in the background color.

### `D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_DESTINATION`

Existing alpha values remain unchanged in the output surface.

### `D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_SOURCE_STREAM`

Alpha values are taken from an input stream, scaled, and copied to the corresponding destination rectangle for that stream. The input stream is specified in the *AlphaFillModeSourceStreamIndex* member of [D3D12_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments).

If the input stream does not have alpha data, the video processor sets the alpha values in the target rectangle to opaque. If the input stream is disabled or the source rectangle is empty, the alpha values in the target rectangle are not modified.

## Remarks

**D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_OPAQUE** must be always supported. The background, destination, and source stream modes are only supported when the driver reports [D3D12_VIDEO_PROCESS_FEATURE_FLAG_ALPHA_FILL](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_feature_flags).

## See also