## Description

Draws the outline of a rectangle that has the specified dimensions and stroke style.

## Parameters

### `rect`

Type: [in] **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f) &**

The dimensions of the rectangle to draw, in device-independent pixels.

### `brush`

Type: [in] **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the rectangle's stroke.

### `strokeWidth`

Type: [in] **FLOAT**

The width of the stroke, in device-independent pixels. The value must be greater than or equal to 0.0f. If this parameter isn't specified, it defaults to 1.0f. The stroke is centered on the line.

### `strokeStyle`

Type: [in, optional] **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of stroke to paint, or **NULL** to paint a solid stroke.

## Remarks

When this method fails, it does not return an error code. To determine whether a drawing method (such as [DrawRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawrectangle(constd2d1_rect_f_id2d1brush_float_id2d1strokestyle))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) method.

## Examples

The following example uses an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget) to draw and fill several rectangles. This example produces the output shown in the following illustration.

![Illustration of two rectangles on a grid background](https://learn.microsoft.com/windows/win32/api/d2d1/images/drawrectangleexample_small.png)

```cpp
// This method discards device-specific
// resources if the Direct3D device disappears during execution and
// recreates the resources the next time it's invoked.
HRESULT DemoApp::OnRender()
{
    HRESULT hr = S_OK;

    hr = CreateDeviceResources();

    if (SUCCEEDED(hr))
    {
        m_pRenderTarget->BeginDraw();

        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

        D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();

        // Draw a grid background.
        int width = static_cast<int>(rtSize.width);
        int height = static_cast<int>(rtSize.height);

        for (int x = 0; x < width; x += 10)
        {
            m_pRenderTarget->DrawLine(
                D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
                D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
                m_pLightSlateGrayBrush,
                0.5f
                );
        }

        for (int y = 0; y < height; y += 10)
        {
            m_pRenderTarget->DrawLine(
                D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
                D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
                m_pLightSlateGrayBrush,
                0.5f
                );
        }

        // Draw two rectangles.
        D2D1_RECT_F rectangle1 = D2D1::RectF(
            rtSize.width/2 - 50.0f,
            rtSize.height/2 - 50.0f,
            rtSize.width/2 + 50.0f,
            rtSize.height/2 + 50.0f
            );

        D2D1_RECT_F rectangle2 = D2D1::RectF(
            rtSize.width/2 - 100.0f,
            rtSize.height/2 - 100.0f,
            rtSize.width/2 + 100.0f,
            rtSize.height/2 + 100.0f
            );

        // Draw a filled rectangle.
        m_pRenderTarget->FillRectangle(&rectangle1, m_pLightSlateGrayBrush);

        // Draw the outline of a rectangle.
        m_pRenderTarget->DrawRectangle(&rectangle2, m_pCornflowerBlueBrush);

        hr = m_pRenderTarget->EndDraw();
    }

    if (hr == D2DERR_RECREATE_TARGET)
    {
        hr = S_OK;
        DiscardDeviceResources();
    }

    return hr;
}
```

For a related tutorial, see [Create a simple Direct2D application](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-quickstart).

## See also

[Create a simple Direct2D application](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-quickstart)

[How to Draw and Fill a Basic Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-an-ellipse)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)