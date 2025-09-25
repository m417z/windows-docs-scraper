# IMF2DBuffer::ContiguousCopyFrom

## Description

Copies data to this buffer from a buffer that has a contiguous format.

## Parameters

### `pbSrcBuffer` [in]

Pointer to the source buffer. The caller allocates the buffer.

### `cbSrcBuffer` [in]

Size of the source buffer, in bytes. To get the maximum size of the buffer, call [IMF2DBuffer::GetContiguousLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-getcontiguouslength).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method copies the contents of the source buffer into the buffer that is managed by this [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) object. The source buffer must be in contiguous format. While copying, the method converts the contents into the destination buffer's native format, correcting for the buffer's pitch if necessary.

For a definition of contiguous as it applies to 2-D buffers, see the Remarks section in the [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface topic.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)