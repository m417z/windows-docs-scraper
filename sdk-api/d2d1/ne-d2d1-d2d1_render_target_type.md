# D2D1_RENDER_TARGET_TYPE enumeration

## Description

Describes whether a render target uses hardware or software rendering, or if Direct2D should select the rendering mode.

## Constants

### `D2D1_RENDER_TARGET_TYPE_DEFAULT:0`

The render target uses hardware rendering, if available; otherwise, it uses software rendering.

### `D2D1_RENDER_TARGET_TYPE_SOFTWARE:1`

The render target uses software rendering only.

### `D2D1_RENDER_TARGET_TYPE_HARDWARE:2`

The render target uses hardware rendering only.

### `D2D1_RENDER_TARGET_TYPE_FORCE_DWORD:0xffffffff`

## Remarks

Not every render target supports hardware rendering. For more information, see the [Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview).

## See also

[D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)

[Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview)