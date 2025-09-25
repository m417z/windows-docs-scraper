## Description

Creates a bitmap render target for use during intermediate offscreen drawing that is compatible with the current render target.

## Parameters

### `desiredSize`

Type: [in] **[D2D1_SIZE_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-f)**

The desired size of the new render target (in device-independent pixels), if it should be different from the original render target. For more info, see the Remarks section.

### `desiredPixelSize`

Type: [in] **[D2D1_SIZE_U](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-u)**

The desired size of the new render target in pixels if it should be different from the original render target. For more information, see the Remarks section.

### `desiredFormat`

Type: [in] **[D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/win32/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The desired pixel format and alpha mode of the new render target. If the pixel format is set to DXGI_FORMAT_UNKNOWN, the new render target uses the same pixel format as the original render target. If the alpha mode is [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-d2d1_alpha_mode), the alpha mode of the new render target defaults to **D2D1_ALPHA_MODE_PREMULTIPLIED**. For information about supported pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

### `bitmapRenderTarget`

Type: [out] **[ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget)****

When this method returns, contains a pointer to a pointer to a new bitmap render target. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

The pixel size and DPI of the new render target can be altered by specifying values for *desiredSize* or *desiredPixelSize*.

* If *desiredSize* is specified but *desiredPixelSize* is not, the pixel size is computed from the desired size using the parent target DPI. If the *desiredSize* maps to a integer-pixel size, the DPI of the compatible render target is the same as the DPI of the parent target. If *desiredSize* maps to a fractional-pixel size, the pixel size is rounded up to the nearest integer and the DPI for the compatible render target is slightly higher than the DPI of the parent render target. In all cases, the coordinate (*desiredSize*.width, *desiredSize*.height) maps to the lower-right corner of the compatible render target.
* If the *desiredPixelSize* is specified and *desiredSize* is not, the DPI of the new render target is the same as the original render target.
* If both *desiredSize* and *desiredPixelSize* are specified, the DPI of the new render target is computed to account for the difference in scale.
* If neither *desiredSize* nor *desiredPixelSize* is specified, the new render target size and DPI match the original render target.

The bitmap render target created by this method is not compatible with GDI.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)