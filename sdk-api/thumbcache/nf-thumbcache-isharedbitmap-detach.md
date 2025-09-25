# ISharedBitmap::Detach

## Description

Retrieves the bitmap contained in an [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object, and returns a copy if the contained bitmap resides in shared memory. After calling this method the bitmap is no longer associated with this **ISharedBitmap** and you cannot call [ISharedBitmap::GetSharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-isharedbitmap-getsharedbitmap) or **ISharedBitmap::Detach** on it again.

## Parameters

### `phbm` [out]

Type: **HBITMAP***

When this method returns, contains a pointer to a handle to the bitmap to retrieve.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the bitmap being retrieved resides in shared memory, a copy of the bitmap is returned. The **Detach** method does not release any references to the underlying shared memory.

If the bitmap being retrieved does not reside in shared memory, the bitmap itself is returned and no copy is made.