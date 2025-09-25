# D3D12_VIDEO_PROCESS_FEATURE_FLAGS enumeration

## Description

Specifies the features that a video processor can support.

## Constants

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_NONE`

No features are supported.

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_ALPHA_FILL`

The video processor can set alpha values on the output pixels. The alpha fill mode is used in [D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_output_stream_desc). [D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_OPAQUE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_alpha_fill_mode) must be always supported. The background, destination, and source stream modes are only supported when the driver reports D3D12_VIDEO_PROCESS_FEATURE_FLAG_ALPHA_FILL.

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_LUMA_KEY`

The video processor can perform luma keying. Luma keying is configured via the **D3D12_VIDEO_PROCESS_LUMA_KEY** member of the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure. For more information see [D3D12_VIDEO_PROCESS_LUMA_KEY](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_luma_key"").

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_STEREO`

The video processor can support 3D stereo video. For more information, see [D3D12_VIDEO_FRAME_STEREO_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_stereo_format).

All drivers setting this capability must support the following stereo formats: D3D12_VIDEO_PROCESS_STEREO_FORMAT_HORIZONTAL, D3D12_VIDEO_PROCESS_STEREO_FORMAT_VERTICAL, and D3D12_VIDEO_PROCESS_STEREO_FORMAT_SEPARATE.

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_ROTATION`

The driver can rotate the input data either 90, 180, or 270 degrees clockwise as part of the video processing operation.

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_FLIP`

The driver can flip the input data horizontally or vertically, together or separately with a video rotation operation.

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_ALPHA_BLENDING`

Alpha blending and a planar alpha may be set in the **AlphaBlending** member of the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure. For more information see [D3D12_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_alpha_blending).

### `D3D12_VIDEO_PROCESS_FEATURE_FLAG_PIXEL_ASPECT_RATIO`

The driver supports changing the pixel aspect ratio. If the driver does not report this capability, then the **SourceAspectRatio** and **DestinationAspectRatio** members of [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure must indicate a 1:1 aspect ratio.

## Remarks

## See also