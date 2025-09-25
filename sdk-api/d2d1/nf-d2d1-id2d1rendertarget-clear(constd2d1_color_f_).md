## Description

Clears the drawing area to the specified color.

## Parameters

### `clearColor`

Type: [in] **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-color-f) &**

The color to which the drawing area is cleared.

## Remarks

Direct2D interprets the *clearColor* as straight alpha (not premultiplied). If the render target's alpha mode is [D2D1_ALPHA_MODE_IGNORE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode), the alpha channel of *clearColor* is ignored and replaced with 1.0f (fully opaque).

If the render target has an active clip (specified by [PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f__d2d1_antialias_mode))), the clear command is applied only to the area within the clip region.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)