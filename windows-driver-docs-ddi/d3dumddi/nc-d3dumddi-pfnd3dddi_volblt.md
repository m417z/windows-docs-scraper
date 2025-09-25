# PFND3DDDI_VOLBLT callback function

## Description

The *VolBlt* function performs a bit-block transfer (bitblt) operation from a source volume texture to a destination volume texture.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_VOLUMEBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_volumeblt) structure that defines the parameters for the volume bitblt operation.

## Return value

*VolBlt* returns S_OK or an appropriate error result if the volume bitblt operation is not successfully performed.

## See also

[D3DDDIARG_VOLUMEBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_volumeblt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)