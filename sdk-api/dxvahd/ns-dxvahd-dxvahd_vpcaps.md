# DXVAHD_VPCAPS structure

## Description

Specifies the capabilities of the Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Members

### `VPGuid`

A GUID that identifies the video processor. This GUID is defined by the device, and is used in various [IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device) methods to specify the video processor.

### `PastFrames`

The number of past reference frames required to perform the optimal video processing.

### `FutureFrames`

The number of future reference frames required to perform the optimal video processing.

### `ProcessorCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_processor_caps) enumeration.

### `ITelecineCaps`

A bitwise **OR** of zero or more flags from the [DXVAHD_ITELECINE_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_itelecine_caps) enumeration.

### `CustomRateCount`

The number of custom output frame rates. To get the list of custom frame rates, call the [IDXVAHD_Device::GetVideoProcessorCustomRates](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcustomrates) method. Custom frame rates are used for frame-rate conversion and inverse telecine.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_Device::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcaps)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)