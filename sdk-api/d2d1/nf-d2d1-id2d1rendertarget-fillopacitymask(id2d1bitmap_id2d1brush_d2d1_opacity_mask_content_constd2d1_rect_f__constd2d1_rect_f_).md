# ID2D1RenderTarget::FillOpacityMask(ID2D1Bitmap,ID2D1Brush,D2D1_OPACITY_MASK_CONTENT,const D2D1_RECT_F &,const D2D1_RECT_F &)

## Description

Applies the opacity mask described by the specified bitmap to a brush and uses that brush to paint a region of the render target.

## Parameters

### `opacityMask` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The opacity mask to apply to the brush. The alpha value of each pixel in the region specified by *sourceRectangle* is multiplied with the alpha value of the brush after the brush has been mapped to the area defined by *destinationRectangle*.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the region of the render target specified by *destinationRectangle*.

### `content`

Type: **[D2D1_OPACITY_MASK_CONTENT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_opacity_mask_content)**

The type of content the opacity mask contains. The value is used to determine the color space in which the opacity mask is blended.

**Note** Starting with Windows 8, the [D2D1_OPACITY_MASK_CONTENT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_opacity_mask_content) is not required. See the [ID2D1DeviceContext::FillOpacityMask](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-fillopacitymask(id2d1bitmap_id2d1brush_constd2d1_rect_f__constd2d1_rect_f)) method, which has no **D2D1_OPACITY_MASK_CONTENT** parameter.

### `destinationRectangle` [ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)**

The region of the render target to paint, in device-independent pixels.

### `sourceRectangle` [ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)**

The region of the bitmap to use as the opacity mask, in device-independent pixels.

## Remarks

For this method to work properly, the render target must be using the [D2D1_ANTIALIAS_MODE_ALIASED](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_antialias_mode) antialiasing mode. You can set the antialiasing mode by calling the [ID2D1RenderTarget::SetAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-setantialiasmode) method.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [FillOpacityMask](https://learn.microsoft.com/windows/win32/Direct2D/id2d1rendertarget-fillopacitymask)) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)