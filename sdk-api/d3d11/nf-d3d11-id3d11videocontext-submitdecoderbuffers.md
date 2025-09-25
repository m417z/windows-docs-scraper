# ID3D11VideoContext::SubmitDecoderBuffers

## Description

Submits one or more buffers for decoding.

## Parameters

### `pDecoder` [in]

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call the [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder) method.

### `NumBuffers` [in]

The number of buffers submitted for decoding.

### `pBufferDesc` [in]

A pointer to an array of [D3D11_VIDEO_DECODER_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_buffer_desc) structures. The *NumBuffers* parameter specifies the number of elements in the array. Each element in the array describes a compressed buffer for decoding.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function does not honor a D3D11 predicate that may have been set.

If the application uses [D3D11 queries](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query), this function may not be accounted for with **D3D11_QUERY_EVENT** and **D3D11_QUERY_TIMESTAMP** when using feature levels lower than 11. **D3D11_QUERY_PIPELINE_STATISTICS** will not include this function for any feature level.

When using feature levels 9_x, all partially encrypted buffers must use the same EncryptedBlockInfo, and partial encryption cannot be turned off on a per frame basis.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)