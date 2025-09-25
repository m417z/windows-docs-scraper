# PFND3DDDI_DISCARD callback function

## Description

Discards (evicts) a set of subresources from video display memory. Implemented by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DISCARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_discard) structure that defines the set of subresources that is to be discarded.

## Return value

 Returns S_OK if successful, or an appropriate error result if the operation is not successful.

## See also

[D3DDDIARG_DISCARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_discard)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)