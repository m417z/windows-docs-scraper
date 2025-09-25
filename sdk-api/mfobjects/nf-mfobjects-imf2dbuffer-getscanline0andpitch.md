# IMF2DBuffer::GetScanline0AndPitch

## Description

Retrieves a pointer to the buffer memory and the surface stride.

## Parameters

### `pbScanline0` [out]

Receives a pointer to the first byte of the top row of pixels in the image.

### `plPitch` [out]

Receives the stride, in bytes. For more information, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_INVALID_FUNCTION** | You must lock the buffer before calling this method. |

## Remarks

Before calling this method, you must lock the buffer by calling [IMF2DBuffer::Lock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-lock2d). The pointer returned in *plPitch* is valid only while the buffer remains locked.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)