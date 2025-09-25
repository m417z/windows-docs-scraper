# D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS enumeration

## Description

Specifies flags that indicate the most efficient methods for performing video processing operations.

## Constants

### `D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_ROTATION:0x1`

Multi-plane overlay hardware can perform the rotation operation more efficiently than the [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

### `D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_RESIZE:0x2`

Multi-plane overlay hardware can perform the scaling operation more efficiently than the [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

### `D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_COLOR_SPACE_CONVERSION:0x4`

Multi-plane overlay hardware can perform the colorspace conversion operation more efficiently than the [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

### `D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINT_TRIPLE_BUFFER_OUTPUT:0x8`

The video processor output data should be at least triple buffered for optimal performance.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)