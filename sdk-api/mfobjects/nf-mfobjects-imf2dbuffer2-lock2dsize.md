# IMF2DBuffer2::Lock2DSize

## Description

Gives the caller access to the memory in the buffer.

## Parameters

### `lockFlags` [in]

A member of the [MF2DBuffer_LockFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf2dbuffer_lockflags) enumeration that specifies whether to lock the buffer for reading, writing, or both.

### `ppbScanline0` [out]

Receives a pointer to the first byte of the top row of pixels in the image. The top row is defined as the top row when the image is presented to the viewer, and might not be the first row in memory.

### `plPitch` [out]

Receives the surface stride, in bytes. The stride might be negative, indicating that the image is oriented from the bottom up in memory.

### `ppbBufferStart` [out]

Receives a pointer to the start of the accessible buffer in memory.

### `pcbBufferLength` [out]

Receives the length of the buffer, in bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | Invalid request. The buffer might already be locked with an incompatible locking flag. See Remarks. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## Remarks

When you are done accessing the memory, call [IMF2DBuffer::Unlock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-unlock2d) to unlock the buffer. You must call **Unlock2D** once for each call to **Lock2DSize**.

This method is equivalent to the [IMF2DBuffer::Lock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-lock2d) method. However, **Lock2DSize** is preferred because it enables the caller to validate memory pointers, and because it supports read-only locks. A buffer is not guaranteed to support the [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2) interface. To access a buffer, you should try the following methods in the order listed:

1. **IMF2DBuffer2::Lock2DSize**
2. [IMF2DBuffer::Lock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-lock2d)
3. [IMFMediaBuffer::Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock)

The *ppbBufferStart* and *pcbBufferLength* parameters receive the bounds of the buffer memory. Use these values to guard against buffer overruns. Use the values of *ppbScanline0* and *plPitch* to access the image data. If the image is bottom-up in memory, *ppbScanline0* will point to the last scan line in memory and *plPitch* will be negative. For more information, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

The *lockFlags* parameter specifies whether the buffer is locked for read-only access, write-only access, or read/write access.

* If the buffer is already locked for read-only access, it cannot be locked for write access.
* If the buffer is already locked for write-only access, it cannot be locked for read access.
* If the buffer is already locked for read/write access, it can be locked for read or write access.

When possible, use a read-only or write-only lock, and avoid locking the buffer for read/write access. If the buffer represents a DirectX Graphics Infrastructure (DXGI) surface, a read/write lock can cause an extra copy between CPU memory and GPU memory.

## See also

[IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2)