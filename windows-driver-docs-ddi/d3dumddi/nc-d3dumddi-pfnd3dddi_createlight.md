# PFND3DDDI_CREATELIGHT callback function

## Description

The **CreateLight** function creates a light source.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_CREATELIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createlight) structure that contains the index into the light array.

## Return value

**CreateLight** should return S_OK or an appropriate error result if it cannot successfully create a light source.

## Remarks

The user-mode display driver should enlarge its light array as necessary to accommodate at least as many light sources as specified by the **Index** member in [D3DDDIARG_CREATELIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createlight).

## See also

[D3DDDIARG_CREATELIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createlight)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)