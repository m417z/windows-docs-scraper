# ID3D11VideoContext1::VideoProcessorGetBehaviorHints

## Description

Returns driver hints that indicate which of the video processor operations are best performed using multi-plane overlay hardware rather than [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

## Parameters

### `pVideoProcessor` [in]

Type: **ID3D11VideoProcessor***

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `OutputWidth` [in]

Type: **UINT**

The width of the output stream.

### `OutputHeight` [in]

Type: **UINT**

The height of the output stream.

### `OutputFormat` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The format of the output stream.

### `StreamCount` [in]

Type: **UINT**

The number of input streams to process.

### `pStreams` [in]

Type: **const [D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_processor_stream_behavior_hint)***

An array of structures that specifies the format of each input stream and whether each stream should be used when computing behavior hints.

### `pBehaviorHints` [out]

Type: **UINT***

A pointer to a bitwise OR combination of [D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_video_processor_behavior_hints) values indicating which video processor operations would best be performed using multi-plane overlay hardware rather than the [ID3D11VideoContext::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt) method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |
| E_OUTOFMEMORY | There is insufficient memory to complete the operation. |

## Remarks

This method computes the behavior hints using the current state of the video processor as set by the "SetOutput" and "SetStream" methods of [ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext) and [ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1). You must set the proper state before calling this method to ensure that the returned hints contain useful data.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)