# D3D11_1DDI_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS structure

## Description

Defines a group of video processor capabilities that are associated with frame-rate conversion, including deinterlacing and inverse telecine.

## Members

### `PastFrames`

The number of past reference frames required to perform the optimal video processing.

### `FutureFrames`

The number of future reference frames required to perform the optimal video processing.

### `ConversionCaps`

A bitwise **OR** of zero or more member values from the [D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_conversion_caps) structure.

### `ITelecineCaps`

A bitwise **OR** of zero or more constant values from the [D3D11_1DDI_VIDEO_PROCESSOR_ITELECINE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_itelecine_caps) enumeration.

### `CustomRateCount`

The number of custom frame rates that the driver supports. To get the list of custom frame rates, call the [GetVideoProcessorCustomRate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcustomrate) function.

## See also

[D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_conversion_caps)

[D3D11_1DDI_VIDEO_PROCESSOR_ITELECINE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_itelecine_caps)

[D3D11_1DDI_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_rate_conversion_caps)

[GetVideoProcessorCustomRate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcustomrate)