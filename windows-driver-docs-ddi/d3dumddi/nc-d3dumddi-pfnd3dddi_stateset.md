# PFND3DDDI_STATESET callback function

## Description

The *StateSet* function sets a state block.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_STATESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_stateset) structure that describes how to set the state block.

## Return value

*StateSet* returns S_OK or an appropriate error result if the state block is not successfully set.

## See also

[D3DDDIARG_STATESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_stateset)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)