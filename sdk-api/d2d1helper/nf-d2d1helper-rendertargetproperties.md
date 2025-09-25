# RenderTargetProperties function

## Description

Creates a [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties) structure.

## Parameters

### `type`

Type: **[D2D1_RENDER_TARGET_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_render_target_type)**

A value that specifies whether the render target must use hardware rendering or software rendering. The default value, [D2D1_RENDER_TARGET_TYPE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_render_target_type), specifies that hardware rendering be used; if hardware rendering is not available, the render target uses software rendering. Note that WIC bitmap render targets do not support hardware rendering.

### `pixelFormat` [in]

Type: **const [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The pixel format and alpha mode of the render target. The default pixel format is [D2D1::PixelFormat](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-pixelformat), which tells Direct2D to select a pixel format that is supported by the render target. For a list of pixel formats and alpha modes supported by each render target, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

### `dpiX`

Type: **FLOAT**

The horizontal DPI of the render target. The default value is 0.0. If both *dpiX* and *dpiY* are set to 0.0, the render target uses its default DPI. For more information, see [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties).

### `dpiY`

Type: **FLOAT**

The vertical DPI of the render target. The default value is 0.0. If both *dpiX* and *dpiY* are set to 0.0, the render target uses its default DPI. For more information, see [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties).

### `usage`

Type: **[D2D1_RENDER_TARGET_USAGE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_render_target_usage)**

Specifies how the render target is remotely rendered and whether it should be GDI-compatible. The default value, [D2D1_RENDER_TARGET_USAGE_NONE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_render_target_usage), creates a render target that is not compatible with GDI and that uses Direct3D command-stream remote rendering, if it is available.

### `minLevel`

Type: **[D2D1_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_feature_level)**

The minimum Direct3D feature level that is required for hardware rendering. The default value, [D2D1_FEATURE_LEVEL_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_feature_level), indicates that Direct2D should determine whether the Direct3D feature level of the device is adequate. This field is used only when [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1hwndrendertarget) and [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1dcrendertarget) objects are created. For more information, see [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties).

## Return value

Type: **[D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties)**

A [D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties) that contains the specified settings.

## See also

[D2D1_RENDER_TARGET_PROPERTIES Structure](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_render_target_properties)

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes)