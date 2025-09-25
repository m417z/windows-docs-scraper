## Description

Creates an [ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap) by copying the specified Microsoft Windows Imaging Component (WIC) bitmap.

## Parameters

### `wicBitmapSource`

Type: [in] **[IWICBitmapSource](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmapsource)***

The WIC bitmap to copy.

### `bitmap` [out]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)****

When this method returns, contains a pointer to a pointer to the new bitmap. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Before Direct2D can load a WIC image, it must be converted to a supported pixel format and alpha mode. For a list of supported pixel formats and alpha modes, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes).

## Examples

For examples, see [How to Load a Bitmap from a File](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-direct2d-bitmap-from-a-file) and [How to Load a Bitmap from a Resource](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-bitmap-from-a-resource).

## See also

[How to Load a Bitmap from a File](https://learn.microsoft.com/windows/win32/Direct2D/how-to-load-a-direct2d-bitmap-from-a-file)

[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes)