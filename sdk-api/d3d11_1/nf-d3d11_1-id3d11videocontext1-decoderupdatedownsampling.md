# ID3D11VideoContext1::DecoderUpdateDownsampling

## Description

Updates the decoder downsampling parameters.

## Parameters

### `pDecoder` [in]

Type: **ID3D11VideoDecoder***

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface.

### `pOutputDesc` [in]

Type: **const [D3D11_VIDEO_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_sample_desc)***

The resolution, format, and colorspace of the output/display frames. This is the destination resolution and format of the downsample operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |
| E_OUTOFMEMORY | There is insufficient memory to complete the operation. |

## Remarks

This method can only be called after decode downsampling is enabled by calling [DecoderEnableDownsampling](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-decoderenabledownsampling). This method is only supported if the [D3D11_VIDEO_DECODER_CAPS_DOWNSAMPLE_DYNAMIC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_video_decoder_caps) capability is reported.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)