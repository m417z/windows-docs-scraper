# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMLUMAKEY callback function

## Description

Sets the luma key for an input stream on the video processor.

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

*Lower* [in]

The lower bound for the luma key. The valid range is from zero to one.

**Note** If the *Enable* parameter is FALSE, this parameter is ignored.

### `unnamedParam5`

*Enable* [in]

If **TRUE**, the luma key is enabled on the specified input stream of the video processor.

### `unnamedParam6`

*Upper* [in]

The upper bound for the luma key. The valid range is from zero to one.

**Note** If the *Enable* parameter is FALSE, this parameter is ignored.

## Remarks

The values of *Lower* and *Upper* give the lower and upper bounds of the luma key by using a nominal range from zero to one. Given a format with *n* bits per channel, these values are converted to luma values as follows:

`val = f * ((1 << n)-1)`

Any pixel whose luma value falls within the upper and lower bounds (inclusive) is treated as transparent.

For example, if the pixel format uses 8-bit luma, the upper bound is calculated as follows:

`BYTE Y = BYTE(max(min(1.0, Upper), 0.0) * 255.0)`

Note that the value is clamped to the range from zero to one before multiplying by 255.

The driver reports its ability to support stereo alpha blending for an input stream in the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure that is returned through the [GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function. If the driver supports the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_LUMA_KEY** capability, it can be enabled or disabled to set a luma key on an input stream of the video processor.

**Note** If the driver does not support the **D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_LUMA_KEY** capability, the Microsoft Direct3D runtime does not call the **VideoProcessorSetStreamLumaKey** function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[GetVideoProcessorCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps)