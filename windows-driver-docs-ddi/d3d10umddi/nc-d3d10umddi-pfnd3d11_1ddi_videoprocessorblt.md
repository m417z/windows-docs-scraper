# PFND3D11_1DDI_VIDEOPROCESSORBLT callback function

## Description

Performs a video processing operation on one or more input samples and writes the result to a Direct3D surface.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*hOutputView* [in]

A handle to the resource for the output view of the video processor. This handle was created through a call to the [CreateVideoProcessorOutputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam4`

*OutputFrame* [in]

The zero-based index of the output video frame.

### `unnamedParam5`

*StreamCount* [in]

The number of input streams to process in the array referenced by the *pStream* parameter.

**Note** The maximum value of this parameter is specified by the **MaxStreamStates** member of the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure. The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of that structure.

### `unnamedParam6`

*pStream* [in]

A pointer to an array of [D3D11_1DDI_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_stream) structures that contain information about the input streams.

## Return value

**VideoProcessorBlt** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The video processing operation completed successfully.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The **VideoProcessorBlt** performs all of the video processing based on the stream states and bit-block transfer (bitblt) states that have been previously set.

The Microsoft Direct3D runtime performs the following data validation before it calls the driver's **VideoProcessorBlt** function:

* The input and output [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures may be adjusted if the rectangles are not aligned properly according to the requirements of the format.
* If the video processor has been enabled to produce stereo samples, the output view must contain a texture array of two elements.
  Also, at least one stereo stream must be specified.

  If the video processor has been disabled from producing stereo samples, the output view must contain a single element.
  Also, the stereo format cannot be configured as **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO**.

  **Note** A video processor is enabled or disabled for the production of stereo samples through a call to [VideoProcessorSetOutputStereoMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputstereomode).
* Each input stream is specified through a [D3D11_1DDI_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_stream) structure. If the stereo format of the input stream is configured to be **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, the **pInputSurfaceRight** member must not be set to NULL. Otherwise, the **pInputSurfaceRight** must be set to NULL.

  **Note** The stereo format for an input stream is configured through a call to [VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat).

If multiple input streams are enabled and the video processor is enabled to produce stereo output, it is possible that one of the input streams may be a mono sample.

**Note** This function does not honor a D3D11 predicate that may have been set.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)

**CreateVideoProcessorOutputView**

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[D3D11_1DDI_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_stream)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[VideoProcessorSetOutputStereoMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputstereomode)

[VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat)