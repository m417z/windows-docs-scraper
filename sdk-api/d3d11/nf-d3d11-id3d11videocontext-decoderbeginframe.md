# ID3D11VideoContext::DecoderBeginFrame

## Description

Starts a decoding operation to decode a video frame.

## Parameters

### `pDecoder` [in]

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder).

### `pView` [in]

A pointer to the [ID3D11VideoDecoderOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoderoutputview) interface. This interface describes the resource that will receive the decoded frame. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoderOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoderoutputview).

### `ContentKeySize` [in]

The size of the content key that is specified in *pContentKey*. If *pContentKey* is NULL, set *ContentKeySize* to zero.

### `pContentKey` [in]

An optional pointer to a content key that was used to encrypt the frame data. If no content key was used, set this parameter to **NULL**. If the caller provides a content key, the caller must use the session key to encrypt the content key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. **D3DERR_WASSTILLDRAWING** or **E_PENDING** is returned if the hardware is busy, in which case the decoder should try to make the call again.

## Remarks

After this method is called, call [ID3D11VideoContext::SubmitDecoderBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-submitdecoderbuffers) to perform decoding operations. When all decoding operations have been executed, call [ID3D11VideoContext::DecoderEndFrame](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderendframe).

Each call to **DecoderBeginFrame** must have a matching call to [DecoderEndFrame](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderendframe). In most cases you cannot nest **DecoderBeginFrame** calls, but some codecs, such as like VC-1, can have nested **DecoderBeginFrame** calls for special operations like post processing.

The following encryption scenarios are supported through the content key:

* The decoder can choose to not encrypt every frame, for example it may only encrypt the I frames and not encrypt the P/B frames. In these scenario, the decoder will specify pContentKey = NULL and ContentKeySize = 0 for those frames that it does not encrypt.
* The decoder can choose to encrypt the compressed buffers using the session key. In this scenario, the decoder will specify a content key containing all zeros.
* The decoder can choose to encrypt the compressed buffers using a separate content key. In this scenario, the decoder will ECB encrypt the content key using the session key and pass the encrypted content key.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)