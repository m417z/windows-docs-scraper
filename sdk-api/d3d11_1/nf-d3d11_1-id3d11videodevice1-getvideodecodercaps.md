# ID3D11VideoDevice1::GetVideoDecoderCaps

## Description

Retrieves capabilities and limitations of the video decoder.

## Parameters

### `pDecoderProfile` [in]

Type: **const GUID***

The decode profile for which the capabilities are queried.

### `SampleWidth` [in]

Type: **UINT**

The video width for which the capabilities are queried.

### `SampleHeight` [in]

Type: **UINT**

The video height for which the capabilities are queried.

### `pFrameRate` [in]

Type: **const [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational)***

The frame rate of the video content. This information is used by the driver to determine whether the video can be decoded in real-time.

### `BitRate` [in]

Type: **UINT**

The bit rate of the video stream. A value of zero indicates that the bit rate can be ignored.

### `pCryptoType` [in]

Type: **const GUID***

The type of cryptography used to encrypt the video stream. A value of NULL indicates that the video stream is not encrypted.

### `pDecoderCaps` [out]

Type: **UINT***

A pointer to a bitwise OR combination of [D3D11_VIDEO_DECODER_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_video_decoder_caps) values specifying the decoder capabilities.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |

## See also

[ID3D11VideoDevice1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videodevice1)