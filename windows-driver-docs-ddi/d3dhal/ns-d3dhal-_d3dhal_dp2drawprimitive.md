# _D3DHAL_DP2DRAWPRIMITIVE structure

## Description

 DirectX 8.0 and later versions only.

D3DHAL_DRAWPRIMITIVE is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_DRAWPRIMITIVE, and is used to render a primitive.

## Members

### `primType`

Specifies the type of primitive to draw (one of D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP or D3DPT_TRIANGLEFAN).

### `VStart`

Specifies the index (into each active vertex stream) of the vertex elements with which to start drawing. Actual vertex data should be read from the current vertex streams (those referenced by the current vertex shader) rather than from the vertex data pointer in [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data).

### `PrimitiveCount`

Specifies the number of triangles, lines or points to draw for the given primitive.

## Remarks

The vertex data can be untransformed (if the hardware supports hardware vertex processing) or transformed if the application supplied data in that form to the runtime.

## See also

D3DDP2OP_DRAWPRIMITIVE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)