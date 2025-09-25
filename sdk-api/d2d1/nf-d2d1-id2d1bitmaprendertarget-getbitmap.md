# ID2D1BitmapRenderTarget::GetBitmap

## Description

Retrieves the bitmap for this render target. The returned bitmap can be used for drawing operations.

## Parameters

### `bitmap` [out]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)****

When this method returns, contains the address of a pointer to the bitmap for this render target. This bitmap can be used for drawing operations.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The DPI for the [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) obtained from **GetBitmap** will be the DPI of the [ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget) when the render target was created. Changing the DPI of the **ID2D1BitmapRenderTarget** by calling [SetDpi](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-setdpi) doesn't affect the DPI of the bitmap, even if **SetDpi** is called before **GetBitmap**. Using **SetDpi** to change the DPI of the **ID2D1BitmapRenderTarget** does affect how contents are rendered into the bitmap: it just doesn't affect the DPI of the bitmap retrieved by **GetBitmap**.

## Examples

The following example uses the [CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createcompatiblerendertarget(constd2d1_size_f_constd2d1_size_u_constd2d1_pixel_format_d2d1_compatible_render_target_options_id2d1bitmaprendertarget)) method to create an [ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget) and uses it to draw a grid pattern. The grid pattern is used as the source of an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush).

```cpp
HRESULT DemoApp::CreateGridPatternBrush(
    ID2D1RenderTarget *pRenderTarget,
    ID2D1BitmapBrush **ppBitmapBrush
    )
{
    // Create a compatible render target.
    ID2D1BitmapRenderTarget *pCompatibleRenderTarget = NULL;
    HRESULT hr = pRenderTarget->CreateCompatibleRenderTarget(
        D2D1::SizeF(10.0f, 10.0f),
        &pCompatibleRenderTarget
        );
    if (SUCCEEDED(hr))
    {
        // Draw a pattern.
        ID2D1SolidColorBrush *pGridBrush = NULL;
        hr = pCompatibleRenderTarget->CreateSolidColorBrush(
            D2D1::ColorF(D2D1::ColorF(0.93f, 0.94f, 0.96f, 1.0f)),
            &pGridBrush
            );
        if (SUCCEEDED(hr))
        {
            pCompatibleRenderTarget->BeginDraw();
            pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 10.0f, 1.0f), pGridBrush);
            pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.1f, 1.0f, 10.0f), pGridBrush);
            pCompatibleRenderTarget->EndDraw();

            // Retrieve the bitmap from the render target.
            ID2D1Bitmap *pGridBitmap = NULL;
            hr = pCompatibleRenderTarget->GetBitmap(&pGridBitmap);
            if (SUCCEEDED(hr))
            {
                // Choose the tiling mode for the bitmap brush.
                D2D1_BITMAP_BRUSH_PROPERTIES brushProperties =
                    D2D1::BitmapBrushProperties(D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP);

                // Create the bitmap brush.
                hr = m_pRenderTarget->CreateBitmapBrush(pGridBitmap, brushProperties, ppBitmapBrush);

                pGridBitmap->Release();
            }

            pGridBrush->Release();
        }

        pCompatibleRenderTarget->Release();
    }

    return hr;
}

```

The following code example uses the brush to paint a pattern.

```cpp
// Paint a grid background.
m_pRenderTarget->FillRectangle(
    D2D1::RectF(0.0f, 0.0f, renderTargetSize.width, renderTargetSize.height),
    m_pGridPatternBitmapBrush
    );

```

Code has been omitted from this example.

## See also

[ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget)