# IMF2DBuffer::IsContiguousFormat

## Description

Queries whether the buffer is contiguous in its native format.

## Parameters

### `pfIsContiguous` [out]

Receives a Boolean value. The value is **TRUE** if the buffer is contiguous, and **FALSE** otherwise.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For a definition of contiguous as it applies to 2-D buffers, see the Remarks section in [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface. For non-contiguous buffers, the [IMFMediaBuffer::Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock) method must perform an internal copy.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)