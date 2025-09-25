# D3D11_1DDI_VIDEO_PROCESSOR_STREAM structure

## Description

Contains stream-level data for the [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt) function.

## Members

### `Enable`

Specifies whether this input stream is enabled. If the value is **TRUE**, the [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt) function blits this stream to the output surface. Otherwise, this stream is not blitted.

The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of the [D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps) structure.

### `OutputIndex`

The zero-based index number of the output frame.

### `InputFrameOrField`

The zero-based index number of the input frame or field.

### `PastFrames`

The number of past reference frames.

### `FutureFrames`

The number of future reference frames.

### `pPastSurfaces`

A **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to an array of pointers, allocated by the caller. This array contains the past reference frames for the video processing operation. The number of elements in the array is equal to **PastFrames**.

### `hInputSurface`

A **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to the surface that contains the current input frame.

### `pFutureSurfaces`

A **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to an array of pointers, allocated by the caller. This array contains the future reference frames for the video processing operation. The number of elements in the array is equal to **FutureFrames**.

### `pPastSurfacesRight`

If the stereo 3-D format is **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member is a **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to an array of pointers that contains the past reference frames for the right view. The number of elements in the array is equal to **PastFrames**.

For any other stereo 3-D format, set this member to **NULL**. For more information, see [VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat).

### `hInputSurfaceRight`

If the stereo 3-D format is **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member is a **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to the current input frame for the right view.

For any other stereo 3-D format, set this member to **NULL**.

### `pFutureSurfacesRight`

If the stereo 3-D format is **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member is a **D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW** pointer to an array of pointers that contains the future reference frames for the right view. The number of elements in the array is equal to **FutureFrames**.

For any other stereo 3-D format, set this member to **NULL**.

## Remarks

If the stereo 3-D format is **D3D11_1DDI_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, the **pPastSurfaces**, **pInputSurface**, and **pFutureSurfaces** members contain the left view.

## See also

[D3D11_1DDI_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_caps)

[VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt)

[VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat)