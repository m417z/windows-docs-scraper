# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMSTEREOFORMAT callback function

## Description

Enables or disables stereo 3D video for an input stream on the video processor. In addition, this function specifies the layout of the video frames in memory.

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

If **TRUE**, stereo 3D is enabled for the input stream.

If **FALSE**, stereo 3D is disabled for the input stream.

The driver must ignore the remaining parameters for this function.

### `unnamedParam5`

*StereoFormat* [in]

Specifies the layout of the two stereo views in memory, as a [D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_format) value.

### `unnamedParam6`

*LeftViewFrame0* [in]

If **TRUE**, frame 0 contains the left view. Otherwise, frame 0 contains the right view.

This parameter is ignored for the following [D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_format) values:

* **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_MONO**
* **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**

### `unnamedParam7`

*BaseViewFrame0* [in]

If **TRUE**, frame 0 contains the base view. Otherwise, frame 1 contains the base view.

This parameter is ignored for the following [D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_format) values:

* **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_MONO**
* **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**

### `unnamedParam8`

*FlipMode* [in]

A [D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_flip_mode) enumeration value that specifies whether one of the views is flipped.

### `unnamedParam9`

*MonoOffset* [in]

If the *StereoFormat* parameter is set to **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**, this parameter specifies how to generate the left and right views. For more information, see the Remarks section.

**Note** If the *StereoFormat* parameter is not set to **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**, this parameter must be set to zero and ignored by the driver.

## Remarks

For stereo formats of **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**, the driver processes the *MonoOffset* parameter in the following way:

* If the parameter is positive, the right view is shifted to the right by that many pixels, and the left view is shifted to the left by the same amount.
* If the parameter is negative, the right view is shifted to the left by that many pixels, and the left view is shifted to the right by the same amount.

For stereo formats of **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, the application can set the *BaseViewFrame0* parameter to convert stereo data to mono. The application does this in one of the following ways:

* Specifies a single resource for the mono input data of the base view.
* Specify both resources for the stereo input data of the base view. When [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt) is called, the stream data is passed as a [D3D11_1DDI_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_stream) structure, with the **hInputSurface** member specifying frame 0 and the **hInputSurfaceRight** specifying frame 1.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

[D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FLIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_flip_mode)

[D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_stereo_format)

[D3D11_1DDI_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_stream)

[VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt)