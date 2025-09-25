# ID3D11VideoDevice::GetVideoDecoderConfig

## Description

Gets a decoder configuration that is supported by the driver.

## Parameters

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) structure that describes the video stream.

### `Index` [in]

The zero-based index of the decoder configuration. To get the number of configurations that the driver supports, call [ID3D11VideoDevice::GetVideoDecoderConfigCount](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderconfigcount).

### `pConfig` [out]

A pointer to a [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config) structure. The method fills in the structure with the decoder configuration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)