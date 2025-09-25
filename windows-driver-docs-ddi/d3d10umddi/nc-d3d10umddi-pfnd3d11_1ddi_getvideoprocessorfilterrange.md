# PFND3D11_1DDI_GETVIDEOPROCESSORFILTERRANGE callback function

## Description

Queries the range of values that the display miniport driver supports for a specified video processor filter.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hProcessorEnum* [in]

A handle to a video processor enumeration object that was created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `unnamedParam3`

*Filter* [in]

The type of the video processor filter, specified as a [D3D11_1DDI_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_filter) value.

### `unnamedParam4`

*pFilterRange* [out]

A pointer to a [D3D11_1DDI_VIDEO_PROCESSOR_FILTER_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_filter_range) structure that specifies the range of values for the specified filter.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[D3D11_1DDI_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_filter)

[D3D11_1DDI_VIDEO_PROCESSOR_FILTER_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_filter_range)