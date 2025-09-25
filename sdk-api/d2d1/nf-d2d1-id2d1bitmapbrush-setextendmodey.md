# ID2D1BitmapBrush::SetExtendModeY

## Description

Specifies how the brush vertically tiles those areas that extend past its bitmap.

## Parameters

### `extendModeY`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that specifies how the brush vertically tiles those areas that extend past its bitmap.

## Remarks

Sometimes, the bitmap for a bitmap brush doesn't completely fill the area being painted. When this happens, Direct2D uses the brush's horizontal ([SetExtendModeX](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-setextendmodex)) and vertical (**SetExtendModeY**) extend mode settings to determine how to fill the remaining area.

The following illustration shows the results from every possible combination of the extend modes for an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush): [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode) (CLAMP), **D2D1_EXTEND_MODE_WRAP** (WRAP), and **D2D1_EXTEND_MIRROR** (MIRROR).

![Illustration of a bitmap and the resulting images from various extend modes](https://learn.microsoft.com/windows/win32/api/d2d1/images/bitmapwrap_clamp_mirror.png)

## Examples

The following example shows how to set the bitmap brush's x- and y-extend modes to [D2D1_EXTEND_MIRROR](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode). It then paints the rectangle with the [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush).

It produces the following output.

![Illustration of an original image and the resulting image from setting both x- and y- extend modes to mirror](https://learn.microsoft.com/windows/win32/api/d2d1/images/brushes_ovw_bitmapmirrormirror.png)

```cpp
m_pBitmapBrush->SetExtendModeX(D2D1_EXTEND_MODE_MIRROR);
m_pBitmapBrush->SetExtendModeY(D2D1_EXTEND_MODE_MIRROR);

m_pRenderTarget->FillRectangle(exampleRectangle, m_pBitmapBrush);

```

For more information about bitmap brushes, see the [Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview).

## See also

[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)

[ID2D1BitmapBrush::GetExtendModeY](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-getextendmodey)