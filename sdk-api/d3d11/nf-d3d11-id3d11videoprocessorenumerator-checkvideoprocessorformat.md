# ID3D11VideoProcessorEnumerator::CheckVideoProcessorFormat

## Description

Queries whether the video processor supports a specified video format.

## Parameters

### `Format` [in]

The video format to query, specified as a [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) value.

### `pFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [D3D11_VIDEO_PROCESSOR_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_format_support) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator)