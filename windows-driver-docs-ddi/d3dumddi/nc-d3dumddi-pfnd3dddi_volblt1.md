# PFND3DDDI_VOLBLT1 callback function

## Description

Performs a bit-block transfer (bitblt) operation from a source volume texture to a destination volume texture. Implemented by Windows Display Driver Model (WDDM) 1.2 or later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_VOLUMEBLT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_volumeblt1) structure that defines the parameters for the volume bitblt operation.

## Return value

 Returns S_OK or an appropriate error result if the volume bitblt operation is not successfully performed.

## See also

[D3DDDIARG_VOLUMEBLT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_volumeblt1)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)