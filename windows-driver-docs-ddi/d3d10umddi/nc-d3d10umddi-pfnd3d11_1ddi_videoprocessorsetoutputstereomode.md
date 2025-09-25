# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTSTEREOMODE callback function

## Description

Specifies whether the video processor produces stereo video frames.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*Enable* [in]

If **TRUE**, stereo output is enabled. Otherwise, the video processor produces mono video frames.

## Remarks

By default, the video processor produces mono video frames. If stereo video is enabled, the stereo output format is set through the [VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat) function.

The driver reports its ability to support stereo video modes through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO** capability, it can be enabled or disabled to produce stereo video frames.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO** capability, the Microsoft Direct3D runtime does not call the **VideoProcessorSetOutputStereoMode** function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)

[VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat)