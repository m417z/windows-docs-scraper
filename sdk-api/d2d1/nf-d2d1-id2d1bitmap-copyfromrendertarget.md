# ID2D1Bitmap::CopyFromRenderTarget

## Description

Copies the specified region from the specified render target into the current bitmap.

## Parameters

### `destPoint` [in, optional]

Type: **const [D2D1_POINT_2U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2u)***

In the current bitmap, the upper-left corner of the area to which the region specified by *srcRect* is copied.

### `renderTarget` [in]

Type: **[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)***

The render target that contains the region to copy.

### `srcRect` [in, optional]

Type: **const [D2D1_RECT_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-u)***

The area of *renderTarget* to copy.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

This method does not update the size of the current bitmap. If the contents of the source bitmap do not fit in the current bitmap, this method fails. Also, note that this method does not perform format conversion, and will fail if the bitmap formats do not match.

Calling this method may cause the current batch to flush if the bitmap is active in the batch. If the batch that was flushed does not complete successfully, this method fails. However, this method does not clear the error state of the render target on which the batch was flushed. The failing [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) and tag state will be returned at the next call to [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush).

All clips and layers must be popped off of the render target before calling this method. The method returns [D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) if any clips or layers are currently applied to the render target.

## See also

[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)