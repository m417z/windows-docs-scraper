# ISharedBitmap::GetSharedBitmap

## Description

Retrieves the bitmap contained in an [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object.

## Parameters

### `phbm` [out]

Type: **HBITMAP***

A pointer to a handle to the bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The bitmap retrieved might reside in shared memory.