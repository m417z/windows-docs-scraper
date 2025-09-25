# DXVAHD_VPDEVCAPS structure

## Description

Specifies the capabilities of a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Members

### `DeviceType`

Specifies the device type, as a member of the [DXVAHD_DEVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_type) enumeration.

### `DeviceCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_DEVICE_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_caps) enumeration.

### `FeatureCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_FEATURE_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_feature_caps) enumeration.

### `FilterCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_FILTER_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_filter_caps) enumeration.

### `InputFormatCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_INPUT_FORMAT_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_input_format_caps) enumeration.

### `InputPool`

The memory pool that is required for the input video surfaces.

### `OutputFormatCount`

The number of supported output formats. To get the list of output formats, call the [IDXVAHD_Device::GetVideoProcessorOutputFormats](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessoroutputformats) method.

### `InputFormatCount`

The number of supported input formats. To get the list of input formats, call the [IDXVAHD_Device::GetVideoProcessorInputFormats](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorinputformats) method.

### `VideoProcessorCount`

The number of video processors. Each video processor represents a distinct set of processing capabilities. To get the capabilities of each video processor, call the [IDXVAHD_Device::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcaps) method. To create a video processor, call the [IDXVAHD_Device::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideoprocessor) method.

### `MaxInputStreams`

The maximum number of input streams that can be enabled at the same time.

### `MaxStreamStates`

The maximum number of input streams for which the device can store state data.

## Remarks

In DXVA-HD, the device stores state information for each input stream. These states persist between blits. With each blit, the application selects which streams to enable or disable. Disabling a stream does not affect the state information for that stream.

The **MaxStreamStates** member gives the maximum number of stream states that can be set by the application. The **MaxInputStreams** member gives the maximum number of streams that can be enabled during a blit. These two values can differ.

To set the state data for a stream, call [IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate).

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)