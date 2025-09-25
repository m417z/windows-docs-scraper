# IWICBitmapFrameEncode::SetPalette

## Description

Sets the [IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette) for indexed pixel formats.

## Parameters

### `pIPalette` [in]

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

The [IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette) to use for indexed pixel formats.

The encoder may change the palette to reflect the pixel formats the encoder supports.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method doesn't fail if called on a frame whose pixel format is set to a non-indexed pixel format. If the target pixel format is a non-indexed format, the palette will be ignored.

If you already called [IWICBitmapEncoder::SetPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-setpalette) to set a global palette, this method overrides that palette for the current frame.

The palette must be specified before your first call to [WritePixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarbitmapframeencode-writepixels)/[WriteSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-writesource). Doing so will cause **WriteSource** to use the specified palette when converting the source image to the encoder pixel format. If no palette is specified, a palette will be generated on the first call to **WriteSource**.