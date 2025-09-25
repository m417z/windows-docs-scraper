# ISharedBitmap::GetSize

## Description

Retrieves the size of the bitmap contained in an [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object.

## Parameters

### `pSize` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

When this method returns, contains a pointer to a value that specifies the size, in pixels, of the contained bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.