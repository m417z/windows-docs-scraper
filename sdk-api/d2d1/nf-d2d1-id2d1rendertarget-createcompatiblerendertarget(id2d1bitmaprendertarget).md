## Description

Creates a new bitmap render target for use during intermediate offscreen drawing that is compatible with the current render target and has the same size, DPI, and pixel format (but not alpha mode) as the current render target.

## Parameters

### `bitmapRenderTarget`

Type: [out] **[ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget)****

When this method returns, contains a pointer to a pointer to a new bitmap render target. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The bitmap render target created by this method is not compatible with GDI, and has an alpha mode of [D2D1_ALPHA_MODE_PREMULTIPLIED](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode).

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)