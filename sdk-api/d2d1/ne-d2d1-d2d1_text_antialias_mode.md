# D2D1_TEXT_ANTIALIAS_MODE enumeration

## Description

Describes the antialiasing mode used for drawing text.

## Constants

### `D2D1_TEXT_ANTIALIAS_MODE_DEFAULT:0`

Use the system default. See Remarks.

### `D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE:1`

Use ClearType antialiasing.

### `D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE:2`

Use grayscale antialiasing.

### `D2D1_TEXT_ANTIALIAS_MODE_ALIASED:3`

Do not use antialiasing.

### `D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD:0xffffffff`

## Remarks

This enumeration is used with the [SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode) of an [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget) to specify how text and glyphs are antialiased.

 By default, Direct2D renders text in ClearType mode. Factors that

can downgrade the default quality to grayscale or aliased:

* If the [DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode) value is **DWRITE_RENDERING_MODE_ALIASED** , then the

  default text antialiasing mode is aliased. To change the DirectWrite rendering mode of an [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget), use the [ID2D1RenderTarget::SetTextRenderingParams](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextrenderingparams) method.
* If the [DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode) value is **DWRITE_RENDERING_MODE_OUTLINE**, then the default text

  antialiasing mode is grayscale.
* If the render target has an alpha channel and is not set to [D2D1_ALPHA_MODE_IGNORE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode), then

  the default text antialiasing mode is grayscale.
* If [ID2D1RenderTarget::PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer)) is called without [D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_layer_options)

  (and the corresponding [PopLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-poplayer) has not been called yet), then the default text

  antialiasing mode is grayscale.

## See also

[ID2D1RenderTarget::SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)

[ID2D1RenderTarget::SetTextRenderingParams](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextrenderingparams)