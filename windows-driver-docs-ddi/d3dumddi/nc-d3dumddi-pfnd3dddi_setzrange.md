# PFND3DDDI_SETZRANGE callback function

## Description

The *SetZRange* function informs the driver about the range of z values.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_ZRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_zrange) structure that specifies minimum and maximum values for the range of z values.

## Return value

*SetZRange* returns S_OK or an appropriate error result if the driver is not successfully informed about the range of z values.

## See also

[D3DDDIARG_ZRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_zrange)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)