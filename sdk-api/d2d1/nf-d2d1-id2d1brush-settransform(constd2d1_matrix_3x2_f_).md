# ID2D1Brush::SetTransform(const D2D1_MATRIX_3X2_F &)

## Description

Sets the transformation applied to the brush.

## Parameters

### `transform` [ref]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)**

The transformation to apply to this brush.

## Remarks

When you paint with a brush, it paints in the coordinate space of the render target. Brushes do not automatically position themselves to align with the object being painted; by default, they begin painting at the origin (0, 0) of the render target.

You can "move" the gradient defined by an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush) to a target area by setting its start point and end point. Likewise, you can move the gradient defined by an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush) by changing its center and radii.

To align the content of an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) to the area being painted, you can use the **SetTransform** method to translate the bitmap to the desired location. This transform only affects the brush; it does not affect any other content drawn by the render target.

The following illustrations show the effect of using an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) to fill a rectangle located at (100, 100). The illustration on the left illustration shows the result of filling the rectangle without transforming the brush: the bitmap is drawn at the render target's origin. As a result, only a portion of the bitmap appears in the rectangle.

The illustration on the right shows the result of transforming the [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) so that its content is shifted 50 pixels to the right and 50 pixels down. The bitmap now fills the rectangle.

![Illustration of two squares, one painted with a bitmap without a transformed brush and one painted with a transformed brush](https://learn.microsoft.com/windows/win32/api/d2d1/images/brushes_ovw_transform.png)

## Examples

The following code examples show how to create the transformation shown in the right diagram in the preceding illustration. First apply a translation to the [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush), moving the brush 50 pixels right along the x-axis and 50 pixels down along the y-axis. Then use the **ID2D1BitmapBrush** to fill the rectangle that has the upper-left corner at (100, 100) and the lower-right corner at (200, 200).

```cpp
// Create the bitmap to be used by the bitmap brush.
if (SUCCEEDED(hr))
{
    hr = LoadResourceBitmap(
        m_pRenderTarget,
        m_pWICFactory,
        L"FERN",
        L"Image",
        &m_pBitmap
        );

}

```

```cpp
if (SUCCEEDED(hr))
{
    hr = m_pRenderTarget->CreateBitmapBrush(
        m_pBitmap,
        &m_pBitmapBrush
        );
}

```

```cpp
D2D1_RECT_F rcTransformedBrushRect = D2D1::RectF(100, 100, 200, 200);

```

```cpp
 // Demonstrate the effect of transforming a bitmap brush.
 m_pBitmapBrush->SetTransform(
     D2D1::Matrix3x2F::Translation(D2D1::SizeF(50,50))
     );

 // To see the content of the rcTransformedBrushRect, comment
 // out this statement.
 m_pRenderTarget->FillRectangle(
     &rcTransformedBrushRect,
     m_pBitmapBrush
     );

 m_pRenderTarget->DrawRectangle(rcTransformedBrushRect, m_pBlackBrush, 1, NULL);

```

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)