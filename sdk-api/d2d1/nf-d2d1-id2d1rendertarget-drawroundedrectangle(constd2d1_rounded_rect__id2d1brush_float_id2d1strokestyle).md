## Description

Draws the outline of the specified rounded rectangle using the specified stroke style.

## Parameters

### `roundedRect`

Type: [in] **const [D2D1_ROUNDED_RECT](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_rounded_rect) &**

The dimensions of the rounded rectangle to draw, in device-independent pixels.

### `brush`

Type: [in] **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the rounded rectangle's outline.

### `strokeWidth`

Type: [in] **FLOAT**

The width of the stroke, in device-independent pixels. The value must be greater than or equal to 0.0f. If this parameter isn't specified, it defaults to 1.0f. The stroke is centered on the line.

### `strokeStyle`

Type: [in, optional] **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of the rounded rectangle's stroke, or **NULL** to paint a solid stroke. The default value is **NULL**.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [DrawRoundedRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawroundedrectangle(constd2d1_rounded_rect_id2d1brush_float_id2d1strokestyle))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

The following example uses the [DrawRoundedRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawroundedrectangle(constd2d1_rounded_rect_id2d1brush_float_id2d1strokestyle)) and FillRoundedRectangle methods to outline and fill a rounded rectangle. This example produces the output shown in the following illustration.

![Illustration of four rounded rectangles with different stroke styles and fills](https://learn.microsoft.com/windows/win32/api/d2d1/images/drawroundedrectangle_scr.png)

```cpp
//  Called whenever the application needs to display the client
//  window.
HRESULT DrawAndFillRoundedRectangleExample::OnRender()
{
    HRESULT hr;

    // Create the render target and brushes if they
    // don't already exists.
    hr = CreateDeviceResources();

    if (SUCCEEDED(hr))
    {
        // Retrieve the size of the render target.
        D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();

        m_pRenderTarget->BeginDraw();
        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

        // Paint a grid background.
        m_pRenderTarget->FillRectangle(
            D2D1::RectF(0.0f, 0.0f, renderTargetSize.width, renderTargetSize.height),
            m_pGridPatternBitmapBrush
            );

        // Define a rounded rectangle.
        D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(
            D2D1::RectF(20.f, 20.f, 150.f, 100.f),
            10.f,
            10.f
            );

        // Draw the rectangle.
        m_pRenderTarget->DrawRoundedRectangle(roundedRect, m_pBlackBrush, 10.f);

        // Apply a translation transform.
        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(200.f, 0.f));

        // Draw the rounded rectangle again, this time with a dashed stroke.
        m_pRenderTarget->DrawRoundedRectangle(roundedRect, m_pBlackBrush, 10.f, m_pStrokeStyle);

        // Apply another translation transform.
        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(0.f, 150.f));

        // Draw, then fill the rounded rectangle.
        m_pRenderTarget->DrawRoundedRectangle(roundedRect, m_pBlackBrush, 10.f, m_pStrokeStyle);
        m_pRenderTarget->FillRoundedRectangle(roundedRect, m_pSilverBrush);

        // Apply another translation transform.
        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(200.f, 150.f));

        // Fill, then draw the rounded rectangle.
        m_pRenderTarget->FillRoundedRectangle(roundedRect, m_pSilverBrush);
        m_pRenderTarget->DrawRoundedRectangle(roundedRect, m_pBlackBrush, 10.f, m_pStrokeStyle);

        hr = m_pRenderTarget->EndDraw();

        if (hr == D2DERR_RECREATE_TARGET)
        {
            hr = S_OK;
            DiscardDeviceResources();
        }
    }

    return hr;
}
```

## See also

[D2D1::RoundedRect](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-roundedrect)

[How to Draw and Fill a Basic Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-an-ellipse)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)