# ID3D11VideoContext1::SubmitDecoderBuffers1

## Description

Submits one or more buffers for decoding.

## Parameters

### `pDecoder` [in]

Type: **ID3D11VideoDecoder***

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call the [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder) method.

### `NumBuffers` [in]

Type: **UINT**

The number of buffers submitted for decoding.

### `pBufferDesc` [in]

Type: **const [D3D11_VIDEO_DECODER_BUFFER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_decoder_buffer_desc1)***

A pointer to an array of [D3D11_VIDEO_DECODER_BUFFER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_video_decoder_buffer_desc1) structures. The *NumBuffers* parameter specifies the number of elements in the array. Each element in the array describes a compressed buffer for decoding.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

This function does not honor any D3D11 predicate that may have been set.

[D3D11_QUERY_DATA_PIPELINE_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_pipeline_statistics) will not include this function for any feature level.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)