# D2D1_OPACITY_MASK_CONTENT enumeration

## Description

Describes whether an opacity mask contains graphics or text. Direct2D uses this information to determine which gamma space to use when blending the opacity mask.

## Constants

### `D2D1_OPACITY_MASK_CONTENT_GRAPHICS:0`

The opacity mask contains graphics. The opacity mask is blended in the gamma 2.2 color space.

### `D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL:1`

The opacity mask contains non-GDI text. The gamma space used for blending is obtained from the render target's text rendering parameters. ([ID2D1RenderTarget::SetTextRenderingParams](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextrenderingparams)).

### `D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE:2`

The opacity mask contains text rendered using the GDI-compatible rendering mode. The opacity mask is blended using the gamma for GDI rendering.

### `D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD:0xffffffff`

## See also

[FillOpacityMask](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillopacitymask(id2d1bitmap_id2d1brush_d2d1_opacity_mask_content_constd2d1_rect_f__constd2d1_rect_f_))