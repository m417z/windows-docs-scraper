## Description

Creates a layer resource that can be used with this render target and its compatible render targets.

## Parameters

### `size`

Type: [in] **const [D2D1_SIZE_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-f)***

If (0, 0) is specified, no backing store is created behind the layer resource. The layer resource is allocated to the minimum size when [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer)) is called.

### `layer`

Type: [out] **[ID2D1Layer](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1layer)****

When the method returns, contains a pointer to a pointer to the new layer. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The layer automatically resizes itself, as needed.

## Examples

The following example uses a layer to clip a bitmap to a geometric mask. For the complete example, see [How to Clip to a Geometric Mask](https://learn.microsoft.com/windows/win32/Direct2D/how-to-clip-with-layers).

```cpp
HRESULT DemoApp::RenderWithLayer(ID2D1RenderTarget *pRT)
{
    HRESULT hr = S_OK;

    // Create a layer.
    ID2D1Layer *pLayer = NULL;
    hr = pRT->CreateLayer(NULL, &pLayer);

    if (SUCCEEDED(hr))
    {
        pRT->SetTransform(D2D1::Matrix3x2F::Translation(350, 50));

        // Push the layer with the geometric mask.
        pRT->PushLayer(
            D2D1::LayerParameters(D2D1::InfiniteRect(), m_pPathGeometry),
            pLayer
            );

        pRT->DrawBitmap(m_pOrigBitmap, D2D1::RectF(0, 0, 200, 133));
        pRT->FillRectangle(D2D1::RectF(0.f, 0.f, 25.f, 25.f), m_pSolidColorBrush);
        pRT->FillRectangle(D2D1::RectF(25.f, 25.f, 50.f, 50.f), m_pSolidColorBrush);
        pRT->FillRectangle(D2D1::RectF(50.f, 50.f, 75.f, 75.f), m_pSolidColorBrush);
        pRT->FillRectangle(D2D1::RectF(75.f, 75.f, 100.f, 100.f), m_pSolidColorBrush);
        pRT->FillRectangle(D2D1::RectF(100.f, 100.f, 125.f, 125.f), m_pSolidColorBrush);
        pRT->FillRectangle(D2D1::RectF(125.f, 125.f, 150.f, 150.f), m_pSolidColorBrush);

        pRT->PopLayer();
    }

    SafeRelease(&pLayer);

    return hr;
}
```

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[Layers Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-layers-overview)