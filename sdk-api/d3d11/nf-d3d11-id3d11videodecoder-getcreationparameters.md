# ID3D11VideoDecoder::GetCreationParameters

## Description

Gets the parameters that were used to create the decoder.

## Parameters

### `pVideoDesc` [out]

A pointer to a [D3D11_VIDEO_DECODER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_desc) structure that receives a description of the video stream.

### `pConfig` [out]

A pointer to a [D3D11_VIDEO_DECODER_CONFIG](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_config) structure that receives the decoder configuration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder)