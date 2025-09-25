# ID3D11VideoContext::VideoProcessorGetStreamColorSpace

## Description

Gets the color space for an input stream of the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex`

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `pColorSpace` [out]

Receives a [D3D11_VIDEO_PROCESSOR_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_color_space) value that specifies the color space.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)