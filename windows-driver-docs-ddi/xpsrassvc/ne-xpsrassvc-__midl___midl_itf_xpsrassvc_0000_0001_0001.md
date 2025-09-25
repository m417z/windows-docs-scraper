# __MIDL___MIDL_itf_xpsrassvc_0000_0001_0001 enumeration

## Description

The XPSRAS_RENDERING_MODE enumeration specifies the rendering mode to be used by an XPS rasterizer.

## Constants

### `XPSRAS_RENDERING_MODE_ANTIALIASED`

Use antialiasing to rasterize the specified graphics elements.

### `XPSRAS_RENDERING_MODE_ALIASED`

Do not use antialiasing to rasterize the specified graphics elements.

## Remarks

The values defined in this enumeration are used by the [IXpsRasterizationFactory::CreateRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizationfactory-createrasterizer) method.

For more information about rasterizing XPS documents, see [Using the XPS Rasterization Service](https://learn.microsoft.com/windows-hardware/drivers/print/using-the-xps-rasterization-service).

## See also

[IXpsRasterizationFactory::CreateRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizationfactory-createrasterizer)