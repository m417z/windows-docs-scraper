# ID3D11VideoDevice::CreateVideoDecoder

## Description

Creates a video decoder device for Microsoft Direct3D 11.

## Parameters

### `pVideoDesc` [in]

A pointer to a [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) structure that describes the video stream and the decoder profile.

### `pConfig` [in]

A pointer to a [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config) structure that specifies the decoder configuration.

### `ppDecoder` [out]

Receives a pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method allocates the necessary decoder buffers.

The [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) method does not affect the internal state of the video decoder.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)