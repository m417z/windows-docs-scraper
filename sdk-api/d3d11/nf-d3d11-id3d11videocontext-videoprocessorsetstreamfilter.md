# ID3D11VideoContext::VideoProcessorSetStreamFilter

## Description

Enables or disables an image filter for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Filter` [in]

The filter, specified as a [D3D11_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_filter) value.

To query which filters the driver supports, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps).

### `Enable` [in]

Specifies whether to enable the filter.

### `Level` [in]

The filter level. If *Enable* is **FALSE**, this parameter is ignored.

To find the valid range of levels for a specified filter, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorFilterRange](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorfilterrange).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)