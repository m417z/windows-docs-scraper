# IXpsRasterizationFactory1::CreateRasterizer

## Description

The **CreateRasterize** method creates an XPS rasterizer object that can handle high precision colors.

## Parameters

### `xpsPage` [in, optional]

Pointer to an **IXpsOMPage** object that represents the XPS fixed page to render. This object encapsulates a FixedPage section from an XPS document. For more information, see [IXpsOMPage](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage).

### `DPI` [in]

Dots per inch in the rasterized output. This parameter applies to both the x and y dimensions of the output bitmap. The *DPI* value is the resolution of the device that is to print or display the XPS fixed page.

### `nonTextRenderingMode` [in]

Rendering mode for nontext items in the rasterized output. This parameter indicates whether to generate antialiased output. Set this parameter to one of the following [XPSRAS_RENDERING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/ne-xpsrassvc-__midl___midl_itf_xpsrassvc_0000_0001_0001) enumeration values:

- XPSRAS_RENDERING_MODE_ANTIALIASED

- XPSRAS_RENDERING_MODE_ALIASED

### `textRenderingMode` [in]

Rendering mode for text in the rasterized output. This parameter indicates whether to generate antialiased output. Set this parameter to one of the following [XPSRAS_RENDERING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/ne-xpsrassvc-__midl___midl_itf_xpsrassvc_0000_0001_0001) enumeration values:

- XPSRAS_RENDERING_MODE_ANTIALIASED

- XPSRAS_RENDERING_MODE_ALIASED

### `pixelFormat`

The *pixelFormat* parameter.

### `ppIXPSRasterizer` [out, optional]

This parameter points to a location into which the method writes a pointer to the [IXpsRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizer) interface of the newly created XPS rasterizer object. If the method fails, it writes **NULL** to this location and returns an error code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IXPSRasterizationFactory1](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizationfactory1)