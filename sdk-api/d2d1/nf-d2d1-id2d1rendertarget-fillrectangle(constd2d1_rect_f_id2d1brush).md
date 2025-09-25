## Description

Paints the interior of the specified rectangle.

## Parameters

### `rect`

Type: [in] **const [D2D1_RECT_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-rect-f)***

The dimension of the rectangle to paint, in device-independent pixels.

### `brush`

Type: [in] **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the rectangle's interior.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [FillRectangle](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillrectangle(constd2d1_rect_f_id2d1brush))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

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

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)