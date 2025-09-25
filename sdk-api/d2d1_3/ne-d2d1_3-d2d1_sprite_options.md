# D2D1_SPRITE_OPTIONS enumeration

## Description

Specifies additional aspects of how a sprite batch is to be drawn, as part of a call to [ID2D1DeviceContext3::DrawSpriteBatch](https://learn.microsoft.com/windows/win32/api/d2d1_3/nf-d2d1_3-id2d1devicecontext3-drawspritebatch(id2d1spritebatch_id2d1bitmap_d2d1_bitmap_interpolation_mode_d2d1_sprite_options)).

## Constants

### `D2D1_SPRITE_OPTIONS_NONE:0`

Default value. No special drawing configuration. This option yields the best drawing performance.

### `D2D1_SPRITE_OPTIONS_CLAMP_TO_SOURCE_RECTANGLE:1`

Interpolation of bitmap pixels will be clamped to the sprite’s source rectangle.
If the sub-images in your source bitmap have no pixels separating them, then you may see color bleeding when drawing them with D2D1_SPRITE_OPTIONS_NONE.
In that case, consider adding borders between them with your sprite-packing tool, or use this option.
Note that drawing sprites with this option enabled is slower than using D2D1_SPRITE_OPTIONS_NONE.

### `D2D1_SPRITE_OPTIONS_FORCE_DWORD:0xffffffff`