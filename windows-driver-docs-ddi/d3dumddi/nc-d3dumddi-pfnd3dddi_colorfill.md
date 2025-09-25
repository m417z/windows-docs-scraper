# PFND3DDDI_COLORFILL callback function

## Description

The **ColorFill** function fills a rectangle on the surface with a particular color.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_COLORFILL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_colorfill) structure that describes the parameters of the color-fill operation.

## Return value

**ColorFill** returns S_OK or an appropriate error result if the color-fill operation is not successfully performed.

## See also

[D3DDDIARG_COLORFILL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_colorfill)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)