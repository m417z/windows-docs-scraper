# D2D1_EXTEND_MODE enumeration

## Description

Specifies how a brush paints areas outside of its normal content area.

## Constants

### `D2D1_EXTEND_MODE_CLAMP:0`

Repeat the edge pixels of the brush's content for all regions outside the normal content area.

### `D2D1_EXTEND_MODE_WRAP:1`

Repeat the brush's content.

### `D2D1_EXTEND_MODE_MIRROR:2`

 The same as D2D1_EXTEND_MODE_WRAP, except that alternate tiles of the brush's content are flipped. (The brush's normal content is drawn untransformed.)

### `D2D1_EXTEND_MODE_FORCE_DWORD:0xffffffff`

## Remarks

For an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush), the brush's content is the brush's bitmap. For an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush), the brush's content area is the gradient axis. For an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush), the brush's content is the area within the gradient ellipse.

## See also

[ID2D1BitmapBrush::SetExtendModeX](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-setextendmodex)

[ID2D1BitmapBrush::SetExtendModeY](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-setextendmodey)

[ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_id2d1gradientstopcollection))