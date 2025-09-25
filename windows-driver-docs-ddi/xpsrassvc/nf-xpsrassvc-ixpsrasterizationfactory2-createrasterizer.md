## Description

The **CreateRasterizer** method creates an XPS rasterizer object that can convert content from XPS to PWG Raster using the [XPS Rasterization Service](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/). PWG Raster supports non-square DPIs.

## Parameters

### `xpsPage` [in, optional]

Pointer to an **IXpsOMPage** object that represents the XPS fixed page to render. This object encapsulates a FixedPage section from an XPS document.

### `DPIX` [in]

Dots per inch which is applied to x dimension of the rasterized output bitmap. The DPI value is the resolution of the device that is to print or display the XPS fixed page.

### `DPIY` [in]

Dots per inch which is applied to y dimension of the rasterized output bitmap.

### `nonTextRenderingMode` [in]

Rendering mode for nontext items in the rasterized output. This parameter indicates whether to generate antialiased output. Set this parameter to one of the following [XPSRAS_RENDERING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/ne-xpsrassvc-__midl___midl_itf_xpsrassvc_0000_0001_0001) enumeration values:

- XPSRAS_RENDERING_MODE_ANTIALIASED

- XPSRAS_RENDERING_MODE_ALIASED

### `textRenderingMode` [in]

Rendering mode for text in the rasterized output. This parameter indicates whether to generate antialiased output. Set this parameter to one of the following XPSRAS_RENDERING_MODE enumeration values:

- XPSRAS_RENDERING_MODE_ANTIALIASED

- XPSRAS_RENDERING_MODE_ALIASED

### `pixelFormat` [in]

Allows a caller to select the pixel format used by the IWICBitmap returned by [IXpsRasterizer::RasterizeRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizer-rasterizerect). Set this parameter to one of the following [XPSRAS_PIXEL_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/ne-xpsrassvc-__midl___midl_itf_xpsrassvc_0000_0003_0001) enumeration values:

- XPSRAS_PIXEL_FORMAT_32BPP_PBGRA_UINT_SRGB

- XPSRAS_PIXEL_FORMAT_64BPP_PRGBA_HALF_SCRGB

- XPSRAS_PIXEL_FORMAT_128BPP_PRGBA_FLOAT_SCRGB

### `backgroundColor` [in]

Allows a caller to select background color. Set this parameter to one of the following [XPSRAS_BACKGROUND_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/ne-xpsrassvc-__midl___midl_itf_xpsrassvc_0000_0004_0001) enumeration values:

- XPSRAS_BACKGROUND_COLOR_TRANSPARENT

- XPSRAS_BACKGROUND_COLOR_OPAQUE

- The default background color is XPSRAS_BACKGROUND_COLOR_TRANSPARENT.

### `ppIXpsRasterizer` [out, optional]

This parameter points to a location into which the method writes a pointer to the [IXpsRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizer) interface of the newly created XPS rasterizer object. If the method fails, it writes **NULL** to this location and returns an error code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IXpsRasterizationFactory2](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizationfactory2)