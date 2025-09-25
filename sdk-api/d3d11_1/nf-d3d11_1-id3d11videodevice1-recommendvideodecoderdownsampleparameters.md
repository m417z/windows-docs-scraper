# ID3D11VideoDevice1::RecommendVideoDecoderDownsampleParameters

## Description

Allows the driver to recommend optimal output downsample parameters from the input parameters.

## Parameters

### `pInputDesc` [in]

Type: **const [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc)***

A [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) object describing the decoding profile, the resolution, and format of the input stream. This is the resolution and format to be downsampled.

### `InputColorSpace` [in]

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

A [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value that specifies the colorspace of the reference frame data.

### `pInputConfig` [in]

Type: **const [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config)***

The configuration data associated with the decode profile.

### `pFrameRate` [in]

Type: **const [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational)***

The frame rate of the video content. This is used by the driver to determine whether the video can be decoded in real-time.

### `pRecommendedOutputDesc` [out]

Type: **[D3D11_VIDEO_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_sample_desc)***

Pointer to a [D3D11_VIDEO_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_sample_desc) structure that the driver populates with the recommended output buffer parameters for a downsample operation. The driver will attempt to recommend parameters that can support real-time decoding. If it is unable to do so, the driver will recommend values that are as close to the real-time solution as possible.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |

## Remarks

You should call [GetVideoDecoderCaps](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videodevice1-getvideodecodercaps) to determine whether decoder downsampling is supported before checking support for a specific configuration.

## See also

[ID3D11VideoDevice1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videodevice1)