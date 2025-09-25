# ID2D1RenderTarget::GetTextRenderingParams

## Description

Retrieves the render target's current text rendering options.

## Parameters

### `textRenderingParams` [out]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)****

 When this method returns, *textRenderingParams* contains the address of a pointer to the render target's current text rendering options.

## Remarks

If the settings specified by *textRenderingParams* are incompatible with the render target's text antialiasing mode (specified by [SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)), subsequent text and glyph drawing operations will fail and put the render target into an error state.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)

[SetTextRenderingParams](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextrenderingparams)