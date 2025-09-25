# IMF2DBuffer::Lock2D

## Description

Gives the caller access to the memory in the buffer.

## Parameters

### `ppbScanline0` [out]

Receives a pointer to the first byte of the top row of pixels in the image. The top row is defined as the top row when the image is presented to the viewer, and might not be the first row in memory.

### `plPitch` [out]

Receives the surface stride, in bytes. The stride might be negative, indicating that the image is oriented from the bottom up in memory.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_INVALIDCALL** | Cannot lock the Direct3D surface. |
| **MF_E_INVALIDREQUEST** | The buffer cannot be locked at this time. |

## Remarks

If *p* is a pointer to the first byte in a row of pixels, *p* + (**plPitch*) points to the first byte in the next row of pixels. A buffer might contain padding after each row of pixels, so the stride might be wider than the width of the image in bytes. Do not access the memory that is reserved for padding bytes, because it might not be read-accessible or write-accessible. For more information, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

The pointer returned in *pbScanline0* remains valid as long as the caller holds the lock. When you are done accessing the memory, call [IMF2DBuffer::Unlock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-unlock2d) to unlock the buffer. You must call **Unlock2D** once for each call to **Lock2D**. After you unlock the buffer, the pointer returned in *pbScanline0* is no longer valid and should not be used. Generally, it is best to call **Lock2D** only when you need to access the buffer memory, and not earlier.

The values returned by the [IMFMediaBuffer::GetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getcurrentlength) and [IMFMediaBuffer::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getmaxlength) methods do not apply to the buffer that is returned by the **Lock2D** method. For the same reason, you do not need to call [IMFMediaBuffer::SetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-setcurrentlength) after manipulating the data in the buffer returned by the **Lock2D** method.

The [IMFMediaBuffer::Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock) method fails while the **Lock2D** lock is held, and vice-versa. Applications should use only one of these methods at a time.

When the underlying buffer is a Direct3D surface, the method fails if the surface is not lockable.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Uncompressed Video Buffers](https://learn.microsoft.com/windows/desktop/medfound/uncompressed-video-buffers)