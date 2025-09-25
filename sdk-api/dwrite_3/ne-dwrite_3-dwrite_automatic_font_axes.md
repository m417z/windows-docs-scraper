## Description

Defines constants that specifies axes that can be applied automatically in layout during font selection. Values can be bitwise OR'd together.

## Constants

### `DWRITE_AUTOMATIC_FONT_AXES_NONE:0x0000`

Specifies that no axes are automatically applied.

### `DWRITE_AUTOMATIC_FONT_AXES_OPTICAL_SIZE:0x0001`

Specifies that—when no value is specified via [DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_axis_tag)—an appropriate optical value should be automatically chosen based on the font size (via [IDWriteTextLayout::SetFontSize](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-setfontsize)). You can still apply the 'opsz' value over text ranges via [IDWriteTextFormat3::SetFontAxisValues](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritetextformat3-setfontaxisvalues), which take priority.

## Remarks

## See also

[DWRITE_FONT_AXIS_TAG enumeration](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_axis_tag)

[IDWriteTextFormat3::SetFontAxisValues](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritetextformat3-setfontaxisvalues)