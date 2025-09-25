# ID3D11VideoContext::GetDecoderBuffer

## Description

Gets a pointer to a decoder buffer.

## Parameters

### `pDecoder` [in]

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder).

### `Type` [in]

The type of buffer to retrieve, specified as a member of the [D3D11_VIDEO_DECODER_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_decoder_buffer_type) enumeration.

### `pBufferSize` [out]

Receives the size of the buffer, in bytes.

### `ppBuffer` [out]

Receives a pointer to the start of the memory buffer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The graphics driver allocates the buffers that are used for decoding. This method locks the Microsoft Direct3Dsurface that contains the buffer. When you are done using the buffer, call [ID3D11VideoContext::ReleaseDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-releasedecoderbuffer) to unlock the surface.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)