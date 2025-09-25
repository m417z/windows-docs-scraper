# PFND3DDDI_SETVIEWPORT callback function

## Description

The *SetViewport* function informs guard-band-aware drivers of the view-clipping rectangle.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_VIEWPORTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_viewportinfo) structure that describes the view-clipping rectangle.

## Return value

*SetViewport* returns S_OK or an appropriate error result if the driver is not successfully informed about the view-clipping rectangle.

## See also

[D3DDDIARG_VIEWPORTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_viewportinfo)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)