# ID3D11VideoContext::VideoProcessorSetStreamAutoProcessingMode

## Description

Enables or disables automatic processing features on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

If **TRUE**, automatic processing features are enabled. If **FALSE**, the driver disables any extra video processing that it might be performing.

## Remarks

By default, the driver might perform certain processing tasks automatically during the video processor blit. This method enables the application to disable these extra video processing features. For example, if you provide your own pixel shader for the video processor, you might want to disable the driver's automatic processing.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)