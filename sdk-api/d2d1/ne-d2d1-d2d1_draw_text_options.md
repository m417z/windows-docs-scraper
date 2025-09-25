# D2D1_DRAW_TEXT_OPTIONS enumeration

## Description

Specifies whether text snapping is suppressed or clipping to the layout rectangle is enabled. This enumeration allows a bitwise combination of its member values.

## Constants

### `D2D1_DRAW_TEXT_OPTIONS_NO_SNAP:0x00000001`

Text is not vertically snapped to pixel boundaries. This setting is recommended for text that is being animated.

### `D2D1_DRAW_TEXT_OPTIONS_CLIP:0x00000002`

Text is clipped to the layout rectangle.

### `D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT:0x00000004`

In Windows 8.1 and later, text is rendered using color versions of glyphs, if defined by the font.

### `D2D1_DRAW_TEXT_OPTIONS_DISABLE_COLOR_BITMAP_SNAPPING:0x00000008`

Bitmap origins of color glyph bitmaps are not snapped.

### `D2D1_DRAW_TEXT_OPTIONS_NONE:0x00000000`

Text is vertically snapped to pixel boundaries and is not clipped to the layout rectangle.

### `D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD:0xffffffff`

## See also

[DrawText](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-drawtext(constwchar_uint32_idwritetextformat_constd2d1_rect_f__id2d1brush_d2d1_draw_text_options_dwrite_measuring_mode))