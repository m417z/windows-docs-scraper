# IMF2DBuffer::ContiguousCopyTo

## Description

Copies this buffer into the caller's buffer, converting the data to contiguous format.

## Parameters

### `pbDestBuffer` [out]

Pointer to the destination buffer where the data will be copied. The caller allocates the buffer.

### `cbDestBuffer` [in]

Size of the destination buffer, in bytes. To get the required size, call [IMF2DBuffer::GetContiguousLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-getcontiguouslength).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid size specified in *pbDestBuffer*. |

## Remarks

If the original buffer is not contiguous, this method converts the contents into contiguous format during the copy. For a definition of contiguous as it applies to 2-D buffers, see the Remarks section in [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)