# PFND3D11_1DDI_VIDEOPROCESSORSETOUTPUTCOLORSPACE callback function

## Description

Sets the output color space for the video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*pColorspace* [in]

A pointer to a [D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_color_space) structure that specifies the color space.

## Remarks

The [D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_color_space) structure includes the following members:

* The **Usage** member specifies whether the output is intended for playback or video processing, such as editing or authoring. The driver can optimize the video processing based on the specified usage.
* The **RGB_Range** member specifies the RGB color range. If this member is set to zero, the transfer matrix is based on the . If this member is set to one, the RGB range is limited to index values from 16 to 235.
* The **YCbCr_Matrix**  member specifies the YCbCr transfer matrix. If this member is set to zero, the transfer matrix is based on the BT.601 format. If this member is set to one, the transfer matrix is based on the BT.709 format.

  **Note** Both of these transfer matrices define the black point as index 16 and the white point as index 235.
* The **YCbCr_xvYCC**  member specifies whether the output uses the conventional YCbCr format or the extended YCbCr (xvYCC) format.

  If this member is set to zero, the format that is used is the conventional YCbCr format.

  If this member is set to one, the format that is used is the extended xvYCC format.

  **Note** The xvYCC format can be used with either YCbCr transfer matrix and also defines the black point as index 16 and the white point as index 235. However, the xvYCC format supports blacker luminance values in the range from 1 to 15. The xvYCC format also supports whiter luminance values in the range from 236 to 254. Therefore, the graphics adapter must not adjust these luminance values to the standard 16 and 235 index values for the white and black point respectively.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_color_space)