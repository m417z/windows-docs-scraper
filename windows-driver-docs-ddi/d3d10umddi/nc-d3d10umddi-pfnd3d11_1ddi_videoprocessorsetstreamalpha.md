# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMALPHA callback function

## Description

Sets the planar alpha for an input stream on the video processor.

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

If **TRUE**, alpha blending is to be enabled on the video processor.

### `unnamedParam5`

*Alpha* [in]

A pointer to a **FLOAT** value that specifies the planar alpha value. The value can range from 0.0 (transparent) to 1.0 (opaque).

**Note** If the *Enable* parameter is **FALSE**, this parameter is ignored.

## Remarks

By default, alpha blending is disabled.

For each pixel, the destination color value is computed as follows:

`Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)`

where:

* `Cd` = The color value of the destination pixel
* `Cs` = The color value of the source pixel
* `As` = The per-pixel source alpha
* `Ap` = The planar alpha value
* `Ae` = The palette-entry alpha value, or 1.0

**Note** Palette-entry alpha values apply only to palettized color formats, and only when the device advertises support for the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. Otherwise, this factor equals 1.0.

The destination alpha value is computed according to the alpha fill mode. For more information, see [VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode)

The driver reports its ability to support stereo alpha blending for an input stream in the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_STREAM**  capability, it can be enabled or disabled to produce stereo video frames.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO** capability, the Microsoft Direct3D runtime does not call the **VideoProcessorSetStreamAlpha** function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)

[VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode)