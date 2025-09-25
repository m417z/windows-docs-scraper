# IMF2DBuffer::GetContiguousLength

## Description

Retrieves the number of bytes needed to store the contents of the buffer in contiguous format.

## Parameters

### `pcbLength` [out]

Receives the number of bytes needed to store the contents of the buffer in contiguous format.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For a definition of contiguous as it applies to 2-D buffers, see the Remarks section in [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)