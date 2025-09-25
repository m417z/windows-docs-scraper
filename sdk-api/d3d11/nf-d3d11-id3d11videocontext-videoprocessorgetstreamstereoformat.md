# ID3D11VideoContext::VideoProcessorGetStreamStereoFormat

## Description

Gets the stereo 3D format for an input stream on the video processor

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `pEnable` [out]

Receives the value **TRUE** if stereo 3D is enabled for this stream, or **FALSE** otherwise. If the value is **FALSE**, ignore the remaining parameters.

### `pFormat` [out]

Receives a [D3D11_VIDEO_PROCESSOR_STEREO_FORMAT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_format) value that specifies the layout of the two stereo views in memory.

### `pLeftViewFrame0` [out]

Receives a Boolean value.

| Value | Meaning |
| --- | --- |
| **TRUE** | Frame 0 contains the left view. |
| **FALSE** | Frame 0 contains the right view. |

### `pBaseViewFrame0` [out]

Receives a Boolean value.

| Value | Meaning |
| --- | --- |
| **TRUE** | Frame 0 contains the base view. |
| **FALSE** | Frame 1 contains the base view. |

### `pFlipMode` [out]

Receives a [D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_flip_mode) value. This value specifies whether one of the views is flipped.

### `MonoOffset` [out]

Receives the pixel offset used for **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET** format. This parameter is ignored for other stereo formats.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)