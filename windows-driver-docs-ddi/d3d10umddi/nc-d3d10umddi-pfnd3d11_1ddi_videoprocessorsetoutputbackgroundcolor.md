# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTBACKGROUNDCOLOR callback function

## Description

Sets the background color for the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*YCbCr* [in]

If **TRUE**, the background color that is specified by the *pColor* parameter is a YCbCr value. Otherwise, the background color is specified as an RGBA value.

### `unnamedParam4`

*pColor* [in]

A pointer to a [D3D11_1DDI_VIDEO_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color) structure that specifies the background color.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color)