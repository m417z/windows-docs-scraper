# ID3D11VideoContext::VideoProcessorSetOutputStereoMode

## Description

Specifies whether the video processor produces stereo video frames.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `Enable`

If **TRUE**, stereo output is enabled. Otherwise, the video processor produces mono video frames.

## Remarks

By default, the video processor produces mono video frames.

To use this feature, the driver must support stereo video, indicated by the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO** capability flag. To query for this capability, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)