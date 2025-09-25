# D2D1_RENDER_TARGET_PROPERTIES structure

## Description

Contains rendering options (hardware or software), pixel format, DPI information, remoting options, and Direct3D support requirements for a render target.

## Members

### `type`

Type: **[D2D1_RENDER_TARGET_TYPE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_type)**

A value that specifies whether the render target should force hardware or software rendering. A value of [D2D1_RENDER_TARGET_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_type) specifies that the render target should use hardware rendering if it is available; otherwise, it uses software rendering. Note that WIC bitmap render targets do not support hardware rendering.

### `pixelFormat`

Type: **[D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/win32/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The pixel format and alpha mode of the render target. You can use the [D2D1::PixelFormat](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-pixelformat) function to create a pixel format that specifies that Direct2D should select the pixel format and alpha mode for you. For a list of pixel formats and alpha modes supported by each render target, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `dpiX`

Type: **FLOAT**

The horizontal DPI of the render target. To use the default DPI, set *dpiX* and *dpiY* to 0. For more information, see the Remarks section.

### `dpiY`

Type: **FLOAT**

The vertical DPI of the render target. To use the default DPI, set *dpiX* and *dpiY* to 0. For more information, see the Remarks section.

### `usage`

Type: **[D2D1_RENDER_TARGET_USAGE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_usage)**

A value that specifies how the render target is remoted and whether it should be GDI-compatible. Set to [D2D1_RENDER_TARGET_USAGE_NONE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_usage) to create a render target that is not compatible with GDI and uses Direct3D command-stream remoting if it is available.

### `minLevel`

Type: **[D2D1_FEATURE_LEVEL](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_feature_level)**

A value that specifies the minimum Direct3D feature level required for hardware rendering. If the specified minimum level is not available, the render target uses software rendering if the **type**  member is set to [D2D1_RENDER_TARGET_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_type); if **type**  is set to **D2D1_RENDER_TARGET_TYPE_HARDWARE**, render target creation fails. A value of [D2D1_FEATURE_LEVEL_DEFAULT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_feature_level) indicates that Direct2D should determine whether the Direct3D feature level of the device is adequate. This field is used only when creating [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget) and [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget) objects.

## Remarks

Use this structure when creating a render target, or use it with the [ID2D1RenderTarget::IsSupported](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-issupported(constd2d1_render_target_properties_)) method to check the properties supported by an existing render target.

As a convenience, Direct2D provides the [D2D1::RenderTargetProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-rendertargetproperties) helper function for creating **D2D1_RENDER_TARGET_PROPERTIES** structures. An easy way to create a **D2D1_RENDER_TARGET_PROPERTIES** structure that works for most render targets is to call the function without specifying any parameters. Doing so creates a **D2D1_RENDER_TARGET_PROPERTIES** structure that has its fields set to default values. For more information, see [D2D1::RenderTargetProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-rendertargetproperties).

Not all render targets support hardware rendering. For a list, see the [Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview).

### Using Default DPI Settings

To use the default DPI, set *dpiX* and *dpiY* to 0. The default DPI varies depending on the render target:

* For a compatible render target, the default DPI is the DPI of the parent render target.
* For a [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget), the default DPI is the system DPI obtained from the render target's [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory).
* For other render targets, the default DPI is 96.

To use the default DPI setting, both *dpiX* and *dpiY* must be set to 0. Setting only one value to 0 causes an [E_INVALIDARG](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-error-codes) error when attempting to create a render target.

## Examples

The following example uses the [D2D1::RenderTargetProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-rendertargetproperties) function to create a **D2D1_RENDER_TARGET_PROPERTIES** structure suitable for most render targets.

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

[ID2D1RenderTarget::IsSupported](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-issupported(constd2d1_render_target_properties_))

[Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview)