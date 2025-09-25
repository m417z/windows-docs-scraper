# D3D11_VIDEO_PROCESSOR_STREAM structure

## Description

Contains stream-level data for the [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

## Members

### `Enable`

Specifies whether this input stream is enabled. If the value is **TRUE**, the [VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method blits this stream to the output surface. Otherwise, this stream is not blitted.

The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of the [D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps) structure.

### `OutputIndex`

The zero-based index number of the output frame.

### `InputFrameOrField`

The zero-based index number of the input frame or field.

### `PastFrames`

The number of past reference frames.

### `FutureFrames`

The number of future reference frames.

### `ppPastSurfaces`

A pointer to an array of [ID3D11VideoProcessorInputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorinputview) pointers, allocated by the caller. This array contains the past reference frames for the video processing operation. The number of elements in the array is equal to **PastFrames**.

### `pInputSurface`

A pointer to the [ID3D11VideoProcessorInputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorinputview) interface of the surface that contains the current input frame.

### `ppFutureSurfaces`

A pointer to an array of [ID3D11VideoProcessorInputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorinputview) pointers, allocated by the caller. This array contains the future reference frames for the video processing operation. The number of elements in the array is equal to **FutureFrames**.

### `ppPastSurfacesRight`

If the stereo 3D format is **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member points to an array that contains the past reference frames for the right view. The number of elements in the array is equal to **PastFrames**.

For any other stereo 3D format, set this member to **NULL**. For more information, see [ID3D11VideoContext::VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat).

### `pInputSurfaceRight`

If the stereo 3D format is **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member contains a pointer to the current input frame for the right view.

For any other stereo 3D format, set this member to **NULL**.

### `ppFutureSurfacesRight`

If the stereo 3D format is **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, this member points to an array that contains the future reference frames for the right view. The number of elements in the array is equal to **FutureFrames**.

For any other stereo 3D format, set this member to **NULL**.

## Remarks

If the stereo 3D format is **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**, the **ppPastSurfaces**, **pInputSurface**, and **ppFutureSurfaces** members contain the left view.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt)