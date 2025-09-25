# ID2D1RenderTarget::SetTextRenderingParams

## Description

Specifies text rendering options to be applied to all subsequent text and glyph drawing operations.

## Parameters

### `textRenderingParams` [in, optional]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

The text rendering options to be applied to all subsequent text and glyph drawing operations; **NULL** to clear current text rendering options.

## Remarks

If the settings specified by *textRenderingParams* are incompatible with the render target's text antialiasing mode (specified by [SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)), subsequent text and glyph drawing operations will fail and put the render target into an error state.

## See also

[GetTextRenderingParams](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-gettextrenderingparams)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)