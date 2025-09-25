# IMFMediaBuffer::Lock

## Description

Gives the caller access to the memory in the buffer, for reading or writing

## Parameters

### `ppbBuffer` [out]

Receives a pointer to the start of the buffer.

### `pcbMaxLength` [out]

Receives the maximum amount of data that can be written to the buffer. This parameter can be **NULL**. The same value is returned by the [IMFMediaBuffer::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getmaxlength) method.

### `pcbCurrentLength` [out]

Receives the length of the valid data in the buffer, in bytes. This parameter can be **NULL**. The same value is returned by the [IMFMediaBuffer::GetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getcurrentlength) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_INVALIDCALL** | For Direct3D surface buffers, an error occurred when locking the surface. |
| **MF_E_INVALIDREQUEST** | The buffer cannot be locked at this time. |

## Remarks

This method gives the caller access to the entire buffer, up to the maximum size returned in the *pcbMaxLength* parameter. The value returned in *pcbCurrentLength* is the size of any valid data already in the buffer, which might be less than the total buffer size.

The pointer returned in *ppbBuffer* is guaranteed to be valid, and can safely be accessed across the entire buffer for as long as the lock is held. When you are done accessing the buffer, call [IMFMediaBuffer::Unlock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-unlock) to unlock the buffer. You must call **Unlock** once for each call to **Lock**. After you unlock the buffer, the pointer returned in *ppbBuffer* is no longer valid, and should not be used. Generally, it is best to call **Lock** only when you need to access the buffer memory, and not earlier.

Locking the buffer does not prevent other threads from calling **Lock**, so you should not rely on this method to synchronize threads.

This method may allocate memory, but does not transfer ownership of the memory to the caller. Do not release or free the memory; the media buffer will free the memory when the media buffer is destroyed.

If you modify the contents of the buffer, update the current length by calling [IMFMediaBuffer::SetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-setcurrentlength).

This method may internally allocate some memory, so if the buffer supports the [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface, you should use the [IMF2DBuffer::Lock2D](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-lock2d) method to lock the buffer instead. For 2-D buffers, the **Lock2DSize** method can be more efficient than the **Lock** method, depending on the **MF2DBuffer_LockFlags** value you specify. Calling **Lock2DSize** with **MF2DBuffer_LockFlags_Read** won’t incur a copy back when the buffer is unlocked and calling it with **MF2DBuffer_LockFlags_Write** won’t incur a copy from the internal buffer. Calling **Lock2DSize** with **LockFlags_ReadWrite** behaves the same as **Lock** and **Lock2D** and will incur a both copy from and copy back when unlocked. The general guidance for best performance is to avoid using **IMFMediaBuffer** and **IMF2DBuffer** whenever possible and instead use **IMF2DBuffer2** with the minimum required lock flags. Note that if the buffer is locked using **Lock2D**, the **Lock** method might return MF_E_INVALIDREQUEST.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)