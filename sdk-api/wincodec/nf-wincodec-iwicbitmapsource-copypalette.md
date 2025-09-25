# IWICBitmapSource::CopyPalette

## Description

Retrieves the color table for indexed pixel formats.

## Parameters

### `pIPalette` [in]

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

An [IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette). A palette can be created using the [CreatePalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createpalette) method.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **WINCODEC_ERR_PALETTEUNAVAILABLE** | The palette was unavailable. |
| **S_OK** | The palette was successfully copied. |

## Remarks

If the [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) is an [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode), the function may return the image's global palette if a frame-level palette is not available.
The global palette may also be retrieved using the [CopyPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapdecoder-copypalette) method.