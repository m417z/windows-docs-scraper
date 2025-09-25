# PFND3DDDI_VALIDATEDEVICE callback function

## Description

The *ValidateDevice* function returns the number of passes in which the hardware can perform the blending operations that are specified in the current state.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_VALIDATETEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_validatetexturestagestate) structure that receives the number of passes in which the hardware can perform the blending operations.

## Return value

*ValidateDevice* returns S_OK or an appropriate error result if the number of necessary hardware passes is not successfully received.

## See also

[D3DDDIARG_VALIDATETEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_validatetexturestagestate)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)