# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMCOLORSPACE callback function

## Description

Sets the color space for an input stream on the video processor.

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

*pColorSpace* [in]

A pointer to a [D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_color_space) structure that specifies the color space for the specified input stream.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_color_space)