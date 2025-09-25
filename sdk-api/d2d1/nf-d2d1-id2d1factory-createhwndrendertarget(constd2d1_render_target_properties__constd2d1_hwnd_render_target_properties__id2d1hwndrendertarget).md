## Description

Creates an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget), a render target that renders to a window.

When you create a render target, and hardware acceleration is available, you allocate resources on the computer's GPU. By creating a render target once and retaining it as long as possible, you gain performance benefits. Your application should create render targets once and hold onto them for the life of the application or until the [D2DERR_RECREATE_TARGET](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error is received. When you receive this error, you need to recreate the render target (and any resources it created).

## Parameters

### `renderTargetProperties`

Type: [in] **const [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties) &**

The rendering mode, pixel format, remoting options, DPI information, and the minimum DirectX support required for hardware rendering. For information about supported pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `hwndRenderTargetProperties`

Type: [in] **const [D2D1_HWND_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_hwnd_render_target_properties) &**

The window handle, initial size (in pixels), and present options.

### `hwndRenderTarget`

Type: [out] **[ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget)****

When this method returns, contains the address of the pointer to the [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget) object created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

When you create a render target and hardware acceleration is available, you allocate resources on the computer's GPU. By creating a render target once and retaining it as long as possible, you gain performance benefits. Your application should create render targets once and hold onto them for the life of the application or until the [D2DERR_RECREATE_TARGET](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error is received. When you receive this error, you need to recreate the render target (and any resources it created).

## Examples

The following example creates an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget).

```cpp
RECT rc;
GetClientRect(m_hwnd, &rc);

D2D1_SIZE_U size = D2D1::SizeU(
    rc.right - rc.left,
    rc.bottom - rc.top
    );

// Create a Direct2D render target.
hr = m_pD2DFactory->CreateHwndRenderTarget(
    D2D1::RenderTargetProperties(),
    D2D1::HwndRenderTargetProperties(m_hwnd, size),
    &m_pRenderTarget
    );
```

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)