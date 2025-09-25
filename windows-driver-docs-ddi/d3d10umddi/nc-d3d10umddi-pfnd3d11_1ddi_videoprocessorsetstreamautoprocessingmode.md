# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMAUTOPROCESSINGMODE callback function

## Description

Enables or disables automatic processing features for an input stream on the video processor.

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

*Enable* [in]

If **TRUE**, automatic processing features are enabled. If **FALSE**, the driver disables any additional video processing that it might be performing.

## Remarks

By default, the driver might perform certain processing tasks automatically during the video processor bit-block transfer (bitblt). The **VideoProcessorSetStreamAutoProcessingMode** function enables the application to disable these additional video processing features that the driver may expose.

For example, if the independent software vendor (ISV) provides its own pixel shader for the video processor, it might want to disable the driver's automatic processing.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)