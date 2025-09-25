# ID2D1RenderTarget::PushLayer(const D2D1_LAYER_PARAMETERS &,ID2D1Layer)

## Description

Adds the specified layer to the render target so that it receives all subsequent drawing operations until [PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer) is called.

## Parameters

### `layerParameters` [ref]

Type: **const [D2D1_LAYER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_layer_parameters)**

The content bounds, geometric mask, opacity, opacity mask, and antialiasing options for the layer.

### `layer` [in]

Type: **[ID2D1Layer](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1layer)***

The layer that receives subsequent drawing operations.

**Note** Starting with Windows 8, this parameter is optional. If a layer is not specified, Direct2D manages the layer resource automatically.

## Remarks

The **PushLayer** method allows a caller to begin redirecting rendering to a layer. All rendering operations are valid in a layer. The location of the layer is affected by the world transform set on the render target.

Each [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters_id2d1layer)) must have a matching [PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer) call. If there are more **PopLayer** calls than **PushLayer** calls, the render target is placed into an error state. If [Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) is called before all outstanding layers are popped, the render target is placed into an error state, and an error is returned. The error state can be cleared by a call to [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw).

A particular [ID2D1Layer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters_id2d1layer)) resource can be active only at one time. In other words, you cannot call a **PushLayer** method, and then immediately follow with another **PushLayer** method with the same layer resource. Instead, you must call the second **PushLayer** method with different layer resources.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters_id2d1layer))) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

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

[PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer)