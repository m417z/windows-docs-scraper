# D2D1_RENDER_TARGET_USAGE enumeration

## Description

Describes how a render target is remoted and whether it should be GDI-compatible. This enumeration allows a bitwise combination of its member values.

## Constants

### `D2D1_RENDER_TARGET_USAGE_NONE:0x00000000`

The render target attempts to use Direct3D command-stream remoting and uses bitmap remoting if stream remoting fails. The render target is not GDI-compatible.

### `D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING:0x00000001`

The render target renders content locally and sends it to the terminal services client as a bitmap.

### `D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE:0x00000002`

The render target can be used efficiently with GDI.

### `D2D1_RENDER_TARGET_USAGE_FORCE_DWORD:0xffffffff`

## See also

[D2D1_RENDER_TARGET_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_render_target_properties)