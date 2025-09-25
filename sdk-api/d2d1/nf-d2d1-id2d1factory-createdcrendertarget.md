# ID2D1Factory::CreateDCRenderTarget

## Description

Creates a render target that draws to a Windows Graphics Device Interface (GDI) device context.

## Parameters

### `renderTargetProperties` [in]

Type: **const [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)***

The rendering mode, pixel format, remoting options, DPI information, and the minimum DirectX support required for hardware rendering. To enable the device context (DC) render target to work with GDI, set the DXGI format to [DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) and the alpha mode to [D2D1_ALPHA_MODE_PREMULTIPLIED](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode) or **D2D1_ALPHA_MODE_IGNORE**. For more information about pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `dcRenderTarget` [out]

Type: **[ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget)****

When this method returns, *dcRenderTarget* contains the address of the pointer to the [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget) created by the method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Before you can render with a DC render target, you must use the render target's [BindDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1dcrendertarget-binddc) method to associate it with a GDI DC. Do this for each different DC and whenever there is a change in the size of the area you want to draw to.

To enable the DC render target to work with GDI, set the render target's DXGI format to [DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) and alpha mode to [D2D1_ALPHA_MODE_PREMULTIPLIED](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode) or **D2D1_ALPHA_MODE_IGNORE**.

Your application should create render targets once and hold on to them for the life of the application or until the render target's [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) method returns the [D2DERR_RECREATE_TARGET](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error. When you receive this error, recreate the render target (and any resources it created).

## Examples

The following code creates a DC render target.

```cpp
// Create a DC render target.
D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
    D2D1_RENDER_TARGET_TYPE_DEFAULT,
    D2D1::PixelFormat(
        DXGI_FORMAT_B8G8R8A8_UNORM,
        D2D1_ALPHA_MODE_IGNORE),
    0,
    0,
    D2D1_RENDER_TARGET_USAGE_NONE,
    D2D1_FEATURE_LEVEL_DEFAULT
    );

hr = m_pD2DFactory->CreateDCRenderTarget(&props, &m_pDCRT);

```

In the preceding code, *m_pD2DFactory* is a pointer to an [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory), and *m_pDCRT* is a pointer to an [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget).

The next code example binds a DC to the [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget).

```cpp
HRESULT DemoApp::OnRender(const PAINTSTRUCT &ps)
{

```

```cpp
// Get the dimensions of the client drawing area.
GetClientRect(m_hwnd, &rc);

```

```cpp
// Bind the DC to the DC render target.
hr = m_pDCRT->BindDC(ps.hdc, &rc);

```

## See also

[Direct2D and GDI Interoperation Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-gdi-interoperation-overview)

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes)