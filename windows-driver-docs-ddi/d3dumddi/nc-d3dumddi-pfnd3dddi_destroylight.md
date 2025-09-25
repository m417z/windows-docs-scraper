# PFND3DDDI_DESTROYLIGHT callback function

## Description

The **DestroyLight** function deactivates a light source.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DESTROYLIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroylight) structure that describes how to set the light source.

## Return value

**DestroyLight** returns S_OK or an appropriate error result if the light source is not successfully deactivated.

## See also

[D3DDDIARG_DESTROYLIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroylight)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)