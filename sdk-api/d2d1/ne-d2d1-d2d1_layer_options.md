# D2D1_LAYER_OPTIONS enumeration

## Description

Specifies options that can be applied when a layer resource is applied to create a layer.

**Note** Starting in Windows 8, the **D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE** option is no longer supported. See [D2D1_LAYER_OPTIONS1](https://learn.microsoft.com/windows/win32/api/d2d1_1/ne-d2d1_1-d2d1_layer_options1) for Windows 8 layer options.

## Constants

### `D2D1_LAYER_OPTIONS_NONE:0x00000000`

The text in this layer does not use ClearType antialiasing.

### `D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE:0x00000001`

The layer renders correctly for ClearType text. If the render target is set to ClearType, the layer continues to render ClearType. If the render target is set to ClearType and this option is not specified, the render target will be set to render gray-scale until the layer is popped. The caller can override this default by calling [SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode) while within the layer. This flag is slightly slower than the default.

### `D2D1_LAYER_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

ClearType antialiasing must use the current contents of the render target to blend properly. When a pushed layer requests initializing for ClearType, Direct2D copies the current contents of the render target into the layer so that ClearType antialiasing can be performed. Rendering ClearType text into a transparent layer does not produce the desired results.

A small performance hit from re-copying content occurs when [ID2D1RenderTarget::Clear](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-clear(constd2d1_color_f_)) is called.

## Examples

The following example shows how to use [CreateLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters_id2d1layer)), PushLayer, and [PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer). All fields in the [D2D1_LAYER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_layer_parameters) structure set to defaults, except **opacityBrush**, which is set to an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush).

```cpp
// Create a layer.
ID2D1Layer *pLayer = NULL;
hr = pRT->CreateLayer(NULL, &pLayer);

if (SUCCEEDED(hr))
{
    pRT->SetTransform(D2D1::Matrix3x2F::Translation(300, 250));

    // Push the layer with the content bounds.
    pRT->PushLayer(
        D2D1::LayerParameters(
            D2D1::InfiniteRect(),
            NULL,
            D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
            D2D1::IdentityMatrix(),
            1.0,
            m_pRadialGradientBrush,
            D2D1_LAYER_OPTIONS_NONE),
        pLayer
        );

    pRT->DrawBitmap(m_pBambooBitmap, D2D1::RectF(0, 0, 190, 127));

    pRT->FillRectangle(
        D2D1::RectF(25.f, 25.f, 50.f, 50.f),
        m_pSolidColorBrush
        );
    pRT->FillRectangle(
        D2D1::RectF(50.f, 50.f, 75.f, 75.f),
        m_pSolidColorBrush
        );
    pRT->FillRectangle(
        D2D1::RectF(75.f, 75.f, 100.f, 100.f),
        m_pSolidColorBrush
        );

    pRT->PopLayer();
}
SafeRelease(&pLayer);

```

For additional examples, see the [Layers Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-layers-overview).

## See also

[Layers Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-layers-overview)