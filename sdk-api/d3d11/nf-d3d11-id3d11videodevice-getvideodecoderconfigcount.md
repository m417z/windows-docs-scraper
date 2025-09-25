# ID3D11VideoDevice::GetVideoDecoderConfigCount

## Description

Gets the number of decoder configurations that the driver supports for a specified video description.

## Parameters

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) structure that describes the video stream.

### `pCount` [out]

Receives the number of decoder configurations.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To enumerate the decoder configurations, call [ID3D11VideoDevice::GetVideoDecoderConfig](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderconfig).

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)