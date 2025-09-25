# ID3D11VideoContext::VideoProcessorSetStreamStereoFormat

## Description

Enables or disables stereo 3D video for an input stream on the video processor. In addition, this method specifies the layout of the video frames in memory.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

Specifies whether stereo 3D is enabled for this stream. If the value is **FALSE**, the remaining parameters of this method are ignored.

### `Format` [in]

Specifies the layout of the two stereo views in memory, as a [D3D11_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_format) value.

### `LeftViewFrame0` [in]

If **TRUE**, frame 0 contains the left view. Otherwise, frame 0 contains the right view.

This parameter is ignored for the following stereo formats:

* **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO**
* **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**

### `BaseViewFrame0` [in]

If **TRUE**, frame 0 contains the base view. Otherwise, frame 1 contains the base view.

This parameter is ignored for the following stereo formats:

* **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO**
* **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**
* When **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE** is used and the application wants to convert the stereo data to mono, it can either:
  + Specify the base view as a mono input.
  + Specify both resources and allow the driver to do the conversion from the base view. In this case, [D3D11_VIDEO_PROCESSOR_STREAM.hInputSurface](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_stream) is considered frame 0 and **D3D11_VIDEO_PROCESSOR_STREAM.hInputSurfaceRight** is considered frame 1.

### `FlipMode` [in]

A flag from the [D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_flip_mode) enumeration, specifying whether one of the views is flipped.

### `MonoOffset` [in]

For **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET** format, this parameter specifies how to generate the left and right views:

* If *MonoOffset* is positive, the right view is shifted to the right by that many pixels, and the left view is shifted to the left by the same amount.
* If *MonoOffset* is negative, the right view is shifted to the left by that many pixels, and the left view is shifted to right by the same amount.

If *Format* is not **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET**, this parameter must be zero.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)