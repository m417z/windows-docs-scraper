# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMFILTER callback function

## Description

Enables or disables an image filter for an input stream on the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*StreamIndex* [in]

The zero-based index of the input stream.

### `unnamedParam4`

*Filter* [in]

The filter, specified as a [D3D11_1DDI_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_filter) value.

### `unnamedParam5`

*Enable* [in]

If **TRUE**, the filter is enabled on the video processor.

### `unnamedParam6`

*Level* [in]

The filter level. The meaning of this value is defined by the independent hardware vendor (IHV).

**Note** If the *Enable* parameter is FALSE, this parameter is ignored.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_filter)