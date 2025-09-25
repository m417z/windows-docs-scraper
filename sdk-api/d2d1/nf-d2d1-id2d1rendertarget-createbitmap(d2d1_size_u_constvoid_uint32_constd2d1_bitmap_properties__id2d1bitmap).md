## Description

Creates a Direct2D bitmap from a pointer to in-memory source data.

## Parameters

### `size`

Type: [in] **[D2D1_SIZE_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-u)**

The dimensions of the bitmap to create in pixels.

### `srcData`

Type: [in, optional] **const void***

A pointer to the memory location of the image data, or **NULL** to create an uninitialized bitmap.

### `pitch`

Type: [in] **UINT32**

The byte count of each scanline, which is equal to (the image width in pixels × the number of bytes per pixel) + memory padding. If *srcData* is **NULL**, this value is ignored. (Note that pitch is also sometimes called *stride*.)

### `bitmapProperties`

Type: [in] **const [D2D1_BITMAP_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_bitmap_properties) &**

The pixel format and dots per inch (DPI) of the bitmap to create.

### `bitmap`

Type: [out] **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)****

When this method returns, contains a pointer to a pointer to the new bitmap. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)