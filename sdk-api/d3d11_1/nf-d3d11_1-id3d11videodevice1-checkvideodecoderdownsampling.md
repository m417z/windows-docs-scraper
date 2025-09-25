# ID3D11VideoDevice1::CheckVideoDecoderDownsampling

## Description

Indicates whether the video decoder supports downsampling with the specified input format, and whether real-time downsampling is supported.

## Parameters

### `pInputDesc` [in]

Type: **const [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc)***

An object describing the decoding profile, the resolution, and format of the input stream. This is the resolution and format to be downsampled.

### `InputColorSpace` [in]

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

A [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value that specifies the colorspace of the reference frame data.

### `pInputConfig` [in]

Type: **const [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config)***

The configuration data associated with the decode profile.

### `pFrameRate` [in]

Type: **const [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational)***

The frame rate of the video content. This is used by the driver to determine whether the video can be decoded in real-time.

### `pOutputDesc` [in]

Type: **const [D3D11_VIDEO_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_sample_desc)***

An object describing the resolution, format, and colorspace of the output frames. This is the destination resolution and format of the downsample operation.

### `pSupported` [out]

Type: **BOOL***

Pointer to a boolean value set by the driver that indicates if downsampling is supported with the specified input data. True if the driver supports the requested downsampling; otherwise, false.

### `pRealTimeHint` [out]

Type: **BOOL***

Pointer to a boolean value set by the driver that indicates if real-time decoding is supported with the specified input data. True if the driver supports the requested real-time decoding; otherwise, false. Note that the returned value is based on the current configuration of the video decoder and does not guarantee that real-time decoding will be supported for future downsampling operations.

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