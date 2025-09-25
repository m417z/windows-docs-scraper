# ID3D11VideoContext::VideoProcessorSetStreamRotation

## Description

Sets the stream rotation for an input stream on the video processor.

## Parameters

### `pVideoProcessor`

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex`

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable`

Specifies if the stream is to be rotated in a clockwise orientation.

### `Rotation`

Specifies the rotation of the stream.

## Remarks

This is an optional state and the application should only use it if [D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ROTATION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_feature_caps) is reported in [D3D11_VIDEO_PROCESSOR_CAPS.FeatureCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps).

The stream source rectangle will be specified in the pre-rotation coordinates (typically landscape) and the stream destination rectangle will be specified in the post-rotation coordinates (typically portrait). The application must update the stream destination rectangle correctly when using a rotation value other than 0° and 180°.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)