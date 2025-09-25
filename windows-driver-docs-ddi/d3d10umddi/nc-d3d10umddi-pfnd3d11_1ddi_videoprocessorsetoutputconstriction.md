# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTCONSTRICTION callback function

## Description

Sets the amount of downsampling to perform on the output.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*Enabled* [in]

If **TRUE**, downsampling is enabled. Otherwise, downsampling is disabled and the *ConstrictonSize* member is ignored.

### `unnamedParam4`

*ConstrictonSize* [in]

The sampling size.

## Remarks

Downsampling is sometimes used to reduce the quality of premium content when other forms of content protection are not available.

By default, downsampling is disabled.

If the *Enable* parameter is TRUE, the display miniport driver downsamples the composed image to the specified size, and then scales it back to the size of the target rectangle.

The width and height of the *ConstrictonSize* parameter must be greater than zero. If the size is larger than the target rectangle, downsampling does not occur.

The driver reports its ability to support downsampling through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_CONSTRICTION** capability, it supports the ability to downsample the composed image.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_CONSTRICTION** capability, the Microsoft Direct3D runtime does not call the **VideoProcessorSetOutputConstriction** function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)