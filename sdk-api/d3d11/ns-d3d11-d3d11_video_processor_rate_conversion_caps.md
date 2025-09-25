# D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS structure

## Description

Defines a group of video processor capabilities that are associated with frame-rate conversion, including deinterlacing and inverse telecine.

## Members

### `PastFrames`

The number of past reference frames required to perform the optimal video processing.

### `FutureFrames`

The number of future reference frames required to perform the optimal video processing.

### `ProcessorCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_processor_caps) enumeration.

### `ITelecineCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_itelecine_caps) enumeration.

### `CustomRateCount`

The number of custom frame rates that the driver supports. To get the list of custom frame rates, call the [ID3D11VideoProcessorEnumerator::GetVideoProcessorCustomRate](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcustomrate) method.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)