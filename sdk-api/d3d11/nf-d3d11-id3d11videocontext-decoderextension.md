# ID3D11VideoContext::DecoderExtension

## Description

Performs an extended function for decoding. This method enables extensions to the basic decoder functionality.

## Parameters

### `pDecoder` [in]

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder).

### `pExtensionData` [in]

A pointer to a [D3D11_VIDEO_DECODER_EXTENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_extension) structure that contains data for the function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)