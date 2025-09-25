# ID3D11VideoContext1::DecoderEnableDownsampling

## Description

Indicates that decoder downsampling will be used and that the driver should allocate the appropriate reference frames.

## Parameters

### `pDecoder` [in]

Type: **ID3D11VideoDecoder***

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface.

### `InputColorSpace` [in]

Type: **DXGI_COLOR_SPACE_TYPE**

The color space information of the reference frame data.

### `pOutputDesc` [in]

Type: **const [D3D11_VIDEO_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_sample_desc)***

The resolution, format, and colorspace of the output/display frames. This is the destination resolution and format of the downsample operation.

### `ReferenceFrameCount` [in]

Type: **UINT**

The number of reference frames to be used in the operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |
| E_OUTOFMEMORY | There is insufficient memory to complete the operation. |

## Remarks

This function can only be called once for a specific [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. This method must be called prior to the first call to [DecoderBeginFrame](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderbeginframe). To update the downsampling parameters, use [DecoderUpdateDownsampling](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-decoderupdatedownsampling).

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)