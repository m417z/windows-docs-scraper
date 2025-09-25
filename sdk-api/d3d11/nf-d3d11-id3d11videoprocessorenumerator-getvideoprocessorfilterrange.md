# ID3D11VideoProcessorEnumerator::GetVideoProcessorFilterRange

## Description

Gets the range of values for an image filter.

## Parameters

### `Filter` [in]

The type of image filter, specified as a [D3D11_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_filter) value.

### `pRange` [out]

A pointer to a [D3D11_VIDEO_PROCESSOR_FILTER_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_filter_range) structure. The method fills the structure with the range of values for the specified filter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator)