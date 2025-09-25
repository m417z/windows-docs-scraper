# D2D1_PIXEL_FORMAT structure

## Description

Contains the data format and alpha mode for a bitmap or render target.

## Members

### `format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A value that specifies the size and arrangement of channels in each pixel.

### `alphaMode`

Type: **[D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode)**

A value that specifies whether the alpha channel is using pre-multiplied alpha, straight alpha, whether it should be ignored and considered opaque, or whether it is unknown.

## Remarks

For more information about the pixel formats and alpha modes supported by each render target, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

#### Examples

The following example creates a **D2D1_PIXEL_FORMAT** structure and uses it to specify the pixel format and alpha mode of an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1hwndrendertarget).

```cpp
RECT rc;
GetClientRect(m_hwnd, &rc);

D2D1_SIZE_U size = D2D1::SizeU(
    rc.right - rc.left,
    rc.bottom - rc.top
    );

// Create a pixel format and initial its format
// and alphaMode fields.
D2D1_PIXEL_FORMAT pixelFormat = D2D1::PixelFormat(
    DXGI_FORMAT_B8G8R8A8_UNORM,
    D2D1_ALPHA_MODE_IGNORE
    );

D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties();
props.pixelFormat = pixelFormat;

// Create a Direct2D render target.
hr = m_pD2DFactory->CreateHwndRenderTarget(
    props,
    D2D1::HwndRenderTargetProperties(m_hwnd, size),
    &m_pRT
    );

```

## See also

[D2D1::PixelFormat](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-pixelformat)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1rendertarget)

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes)