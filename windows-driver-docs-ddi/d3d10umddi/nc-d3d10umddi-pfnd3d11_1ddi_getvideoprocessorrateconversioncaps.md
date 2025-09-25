# PFND3D11_1DDI_GETVIDEOPROCESSORRATECONVERSIONCAPS callback function

## Description

Queries a specified group of video processing capabilities that are associated with frame-rate conversion, including deinterlacing and inverse telecine.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hProcessorEnum* [in]

A handle to a video processor enumeration object that was created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `unnamedParam3`

*RateConversionIndex* [in]

The zero-based index of the frame-rate conversion capability group. For more information, see the Remarks section.

### `unnamedParam4`

*pCaps* [out]

A pointer to a [D3D11_1DDI_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_rate_conversion_caps) structure that contains the attributes of the specified rate conversion capability group.

## Remarks

The display miniport driver returns the maximum number of frame-rate conversion capabilities that it supports through the **RateConversionCapsCount** member of the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure. The driver returns a pointer to this structure through its [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)