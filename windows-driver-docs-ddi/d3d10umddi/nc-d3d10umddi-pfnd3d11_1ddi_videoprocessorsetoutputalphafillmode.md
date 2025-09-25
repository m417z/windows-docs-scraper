# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTALPHAFILLMODE callback function

## Description

Sets the alpha fill mode for data that the video processor writes to the render target.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*FillMode* [in]

The alpha fill mode, specified as a [D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_alpha_fill_mode) value. For more information, see the Remarks section.

### `unnamedParam4`

*StreamIndex* [in]

The zero-based index of an input stream. This parameter is used if the *AlphaFillMode* parameter is set to **D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE_SOURCE_STREAM**. Otherwise, the parameter is ignored.

## Remarks

The driver reports its ability to support alpha fill modes in the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_FILL** capability, it supports all of the alpha fill modes that are defined by the [D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_alpha_fill_mode) enumeration. Otherwise, the *FillMode* parameter must be set to **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE**.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_FILL** capability, the Microsoft Direct3D runtime does not call the **VideoProcessorSetOutputAlphaFillMode** function.

The default fill mode is **D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE_OPAQUE**.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview)

[D3D11_1DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_alpha_fill_mode)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)