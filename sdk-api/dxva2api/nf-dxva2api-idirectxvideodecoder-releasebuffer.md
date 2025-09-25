# IDirectXVideoDecoder::ReleaseBuffer

## Description

Releases a buffer that was obtained by calling [IDirectXVideoDecoder::GetBuffer](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-getbuffer).

## Parameters

### `BufferType` [in]

The type of buffer to release. Specify the same value that was used in the *BufferType* parameter of the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-getbuffer) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder)