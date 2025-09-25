# __MIDL___MIDL_itf_xpsrassvc_0000_0003_0001 enumeration

## Description

**XPSRAS_PIXEL_FORMAT** allows a caller to select the pixel format used by the [IWICBitmap](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmap) interface that is returned by the [IXpsRasterizer::RasterizeRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizer-rasterizerect) method. **XPSRAS_PIXEL_FORMAT** is provided with Windows 8 and later versions of Windows.

## Constants

### `XPSRAS_PIXEL_FORMAT_32BPP_PBGRA_UINT_SRGB`

32-bit color pixel format. It is the default pixel format.

### `XPSRAS_PIXEL_FORMAT_64BPP_PRGBA_HALF_SCRGB`

64-bit color pixel format.

### `XPSRAS_PIXEL_FORMAT_128BPP_PRGBA_FLOAT_SCRGB`

128-bit color pixel format.

## Remarks

For more information about rasterizing XPS documents, see [Using the XPS Rasterization Service](https://learn.microsoft.com/windows-hardware/drivers/print/using-the-xps-rasterization-service).

## See also

[IWICBitmap](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmap)

[IXpsRasterizationFactory1::CreateRasterizer1](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh802468(v=vs.85))

[Using the XPS Rasterization Service](https://learn.microsoft.com/windows-hardware/drivers/print/using-the-xps-rasterization-service)