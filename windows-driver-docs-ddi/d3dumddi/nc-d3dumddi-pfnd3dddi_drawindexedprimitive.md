# PFND3DDDI_DRAWINDEXEDPRIMITIVE callback function

## Description

The **DrawIndexedPrimitive** function draws indexed primitives that the Microsoft Direct3D runtime has not transformed the index data in.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DRAWINDEXEDPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawindexedprimitive) structure that describes the indexed primitive to draw.

## Return value

**DrawIndexedPrimitive** returns S_OK or an appropriate error result if the indexed primitive is not successfully drawn.

## See also

[D3DDDIARG_DRAWINDEXEDPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawindexedprimitive)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2)