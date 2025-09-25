# ID3D11VideoContext::ReleaseDecoderBuffer

## Description

Releases a buffer that was obtained by calling the [ID3D11VideoContext::GetDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-getdecoderbuffer) method.

## Parameters

### `pDecoder` [in]

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder).

### `Type` [in]

The type of buffer to release. Specify the same value that was used in the *Type* parameter of the [GetDecoderBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-getdecoderbuffer) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)