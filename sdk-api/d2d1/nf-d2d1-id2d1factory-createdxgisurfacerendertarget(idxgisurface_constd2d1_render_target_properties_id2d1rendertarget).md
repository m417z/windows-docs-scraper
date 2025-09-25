## Description

Creates a render target that draws to a DirectX Graphics Infrastructure (DXGI) surface.

## Parameters

### `dxgiSurface` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface)***

The IDXGISurface to which the render target will draw.

### `renderTargetProperties` [in]

Type: **const [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)***

The rendering mode, pixel format, remoting options, DPI information, and the minimum DirectX support required for hardware rendering. For information about supported pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `renderTarget` [out]

Type: **[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)****

When this method returns, contains the address of the pointer to the [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget) object created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

To write to a Direct3D surface, you obtain an [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface) and pass it to the CreateDxgiSurfaceRenderTarget method to create a DXGI surface render target; you can then use the DXGI surface render target to draw 2-D content to the DXGI surface.

A DXGI surface render target is a type of [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget). Like other Direct2D render targets, you can use it to create resources and issue drawing commands.

The DXGI surface render target and the DXGI surface must use the same DXGI format. If you specify the [DXGI_FORMAT_UNKOWN](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) format when you create the render target, it will automatically use the surface's format.

The DXGI surface render target does not perform DXGI surface synchronization.

For more information about creating and using DXGI surface render targets, see the [Direct2D and Direct3D Interoperability Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-direct3d-interoperation-overview).

To work with Direct2D, the Direct3D device that provides the [IDXGISurface](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgisurface) must be created with the **D3D10_CREATE_DEVICE_BGRA_SUPPORT** flag.

When you create a render target and hardware acceleration is available, you allocate resources on the computer's GPU. By creating a render target once and retaining it as long as possible, you gain performance benefits. Your application should create render targets once and hold onto them for the life of the application or until the render target's [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) method returns the [D2DERR_RECREATE_TARGET](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error. When you receive this error, you need to recreate the render target (and any resources it created).

## Examples

The following example obtains a DXGI surface (*pBackBuffer*) from an [IDXGISwapChain](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain) and uses it to create a DXGI surface render target.

```cpp
// Initialize *hwnd* with the handle of the window displaying the rendered content.
HWND hwnd;

// Get a surface in the swap chain
hr = m_pSwapChain->GetBuffer(
    0,
    IID_PPV_ARGS(&pBackBuffer));

if (SUCCEEDED(hr))
{
    // Create the DXGI Surface Render Target.
    float dpi = GetDpiForWindow(hwnd);

    D2D1_RENDER_TARGET_PROPERTIES props =
        D2D1::RenderTargetProperties(
            D2D1_RENDER_TARGET_TYPE_DEFAULT,
            D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED),
            dpi,
            dpi
            );

    // Create a Direct2D render target that can draw into the surface in the swap chain.

    hr = m_pD2DFactory->CreateDxgiSurfaceRenderTarget(
        pBackBuffer,
        &props,
        &m_pBackBufferRT);
}
```

## See also

[CreateDxgiSurfaceRenderTarget(IDXGISurface,const D2D1_RENDER_TARGET_PROPERTIES &,ID2D1RenderTarget)](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties__id2d1rendertarget).md)

[Direct2D and Direct3D interoperability overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-direct3d-interoperation-overview)

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)