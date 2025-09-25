# ID2D1Bitmap::CopyFromBitmap

## Description

Copies the specified region from the specified bitmap into the current bitmap.

## Parameters

### `destPoint` [in, optional]

Type: **const [D2D1_POINT_2U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2u)***

In the current bitmap, the upper-left corner of the area to which the region specified by *srcRect* is copied.

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap to copy from.

### `srcRect` [in, optional]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-u)***

The area of *bitmap* to copy.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

This method does not update the size of the current bitmap. If the contents of the source bitmap do not fit in the current bitmap, this method fails. Also, note that this method does not perform format conversion, and will fail if the bitmap formats do not match.

Calling this method may cause the current batch to flush if the bitmap is active in the batch. If the batch that was flushed does not complete successfully, this method fails. However, this method does not clear the error state of the render target on which the batch was flushed. The failing [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) and tag state will be returned at the next call to [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush).

Starting with Windows 8.1, this method supports block compressed bitmaps. If you are using a block compressed format, the end coordinates of the *srcRect* parameter must be multiples of 4 or the method returns **E_INVALIDARG**.

## See also

[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)