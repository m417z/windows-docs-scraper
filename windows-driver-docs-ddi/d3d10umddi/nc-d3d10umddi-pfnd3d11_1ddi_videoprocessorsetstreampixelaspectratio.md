# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMPIXELASPECTRATIO callback function

## Description

Sets the pixel aspect ratio for an input stream on the video processor.

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

If **TRUE**, the *pSourceRatio* and *pDestinationRatio* parameters contain valid values. Otherwise, the pixel aspect ratios are unspecified.

### `unnamedParam5`

*pSourceRatio* [in]

A pointer to a **DXGI_RATIONAL** structure that contains the pixel aspect ratio of the source rectangle.

**Note** If the *Enable* parameter is FALSE, this parameter can be NULL.

### `unnamedParam6`

*pDestRatio* [in]

A pointer to a **DXGI_RATIONAL** structure that contains the pixel aspect ratio of the destination rectangle.

**Note** If the *Enable* parameter is FALSE, this parameter can be NULL.

## Remarks

Pixel aspect ratios of the form 0/*n* and *n*/0 are not valid.

The default pixel aspect ratio is 1:1 (square pixels).

The driver reports its ability to support the pixel aspect ratio capability in the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_PIXEL_ASPECT_RATIO**  capability, the [VideoProcessorSetStreamAlpha](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamalpha) can be called to set the pixel aspect ratios for an input stream of the video processor.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_PIXEL_ASPECT_RATIO**  capability, the Microsoft Direct3D runtime does not call the [VideoProcessorSetStreamAlpha](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamalpha) function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)