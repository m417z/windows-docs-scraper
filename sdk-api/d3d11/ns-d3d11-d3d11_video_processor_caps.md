# D3D11_VIDEO_PROCESSOR_CAPS structure

## Description

Describes the capabilities of a Microsoft Direct3D 11 video processor.

## Members

### `DeviceCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_DEVICE_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_device_caps) enumeration.

### `FeatureCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_FEATURE_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_feature_caps) enumeration.

### `FilterCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSPR_FILTER_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_filter_caps) enumeration.

### `InputFormatCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_FORMAT_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_format_caps) enumeration.

### `AutoStreamCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_AUTO_STREAM_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_auto_stream_caps) enumeration.

### `StereoCaps`

A bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_STEREO_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_caps) enumeration.

### `RateConversionCapsCount`

The number of frame-rate conversion capabilities. To enumerate the frame-rate conversion capabilities, call the [ID3D11VideoProcessorEnumerator::GetVideoProcessorRateConversionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorrateconversioncaps) method.

### `MaxInputStreams`

The maximum number of input streams that can be enabled at the same time.

### `MaxStreamStates`

The maximum number of input streams for which the device can store state data.

## Remarks

The video processor stores state information for each input stream. These states persist between blits. With each blit, the application selects which streams to enable or disable. Disabling a stream does not affect the state information for that stream.

The **MaxStreamStates** member gives the maximum number of stream states that can be saved. The **MaxInputStreams** member gives the maximum number of streams that can be enabled during a blit. These two values can differ.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps)