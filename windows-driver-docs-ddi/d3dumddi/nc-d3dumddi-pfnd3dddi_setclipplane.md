# PFND3DDDI_SETCLIPPLANE callback function

## Description

The *SetClipPlane* function sets a clip plane.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETCLIPPLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setclipplane) structure that describes the clip plane to set.

## Return value

*SetClipPlane* returns S_OK or an appropriate error result if the clip plane is not successfully set.

## Remarks

The coefficients that are passed to *SetClipPlane* in the **Plane** array of the [D3DDDIARG_SETCLIPPLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setclipplane) structure that is pointed to by *pData* are used in the general plane equation. For more information about the general plane equation, see the Remarks section of **D3DDDIARG_SETCLIPPLANE**.

## See also

[D3DDDIARG_SETCLIPPLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setclipplane)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)