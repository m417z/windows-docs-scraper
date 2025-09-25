# D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS enumeration

## Description

Specifies additional features supportable by a compatible render target when it is created.
This enumeration allows a bitwise combination of its member values.

## Constants

### `D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE:0x00000000`

The render target supports no additional features.

### `D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE:0x00000001`

The render target supports interoperability with the Windows Graphics Device Interface (GDI).

### `D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

Use this enumeration when creating a compatible render target with the [CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createcompatiblerendertarget(constd2d1_size_f_constd2d1_size_u_constd2d1_pixel_format_d2d1_compatible_render_target_options_id2d1bitmaprendertarget)) method. For more information about compatible render targets, see the [Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview).

The **D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE** option may only be requested if the parent render target was created with [D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_render_target_usage) (for most render targets) or **D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE** (for render targets created by the [CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createcompatiblerendertarget(constd2d1_size_f_constd2d1_size_u_constd2d1_pixel_format_d2d1_compatible_render_target_options_id2d1bitmaprendertarget)) method).

## See also

[CreateCompatibleRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createcompatiblerendertarget(constd2d1_size_f_constd2d1_size_u_constd2d1_pixel_format_d2d1_compatible_render_target_options_id2d1bitmaprendertarget))

[Render Targets Overview](https://learn.microsoft.com/windows/win32/Direct2D/render-targets-overview)