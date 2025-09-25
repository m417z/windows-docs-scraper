# PFND3DDDI_DRAWPRIMITIVE2 callback function

## Description

The **DrawPrimitive2** function draws nonindexed primitives in which the Microsoft Direct3D runtime has transformed the vertex data.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DRAWPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive2) structure that describes the primitive to draw.

## Return value

**DrawPrimitive2** returns S_OK or an appropriate error result if the primitive is not successfully drawn.

## Remarks

Stream zero contains transform vertices and is the only stream that should be accessed.

## See also

[D3DDDIARG_DRAWPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive2)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)