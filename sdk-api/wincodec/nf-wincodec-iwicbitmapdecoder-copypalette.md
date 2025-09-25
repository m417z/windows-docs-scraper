# IWICBitmapDecoder::CopyPalette

## Description

Copies the decoder's [IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette) .

## Parameters

### `pIPalette` [in]

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

An[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette) to which the decoder's global palette is to be copied. Use [CreatePalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createpalette) to create the destination palette before calling **CopyPalette**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**CopyPalette** returns a global palette (a palette that applies to all the frames in the image) if there is one; otherwise, it returns WINCODEC_ERR_PALETTEUNAVAILABLE. If an image doesn't have a global palette, it may still have a frame-level palette, which can be retrieved using [IWICBitmapFrameDecode::CopyPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypalette).