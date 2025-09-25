# ID2D1RenderTarget::DrawLine

## Description

Draws a line between the specified points using the specified stroke style.

## Parameters

### `point0`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The start point of the line, in device-independent pixels.

### `point1`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The end point of the line, in device-independent pixels.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the line's stroke.

### `strokeWidth`

Type: **FLOAT**

The width of the stroke, in device-independent pixels. The value must be greater than or equal to 0.0f. If this parameter isn't specified, it defaults to 1.0f. The stroke is centered on the line.

### `strokeStyle` [in, optional]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)***

The style of stroke to paint, or **NULL** to paint a solid line.

## Remarks

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as **DrawLine**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## Examples

The following example uses the **DrawLine** method to create a grid that spans the width and height of the render target. The width and height information is provided by the *rtSize* variable.

```cpp
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

```

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)