# ID2D1RenderTarget::SetAntialiasMode

## Description

Sets the antialiasing mode of the render target. The antialiasing mode applies to all subsequent drawing operations, excluding text and glyph drawing operations.

## Parameters

### `antialiasMode`

Type: **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

The antialiasing mode for future drawing operations.

## Remarks

To specify the antialiasing mode for text and glyph operations, use the [SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode) method.

## See also

[GetAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-getantialiasmode)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[SetTextAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settextantialiasmode)