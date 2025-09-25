# _D3DHAL_DP2DRAWPRIMITIVE2 structure

## Description

 DirectX 8.0 and later versions only.

D3DHAL_DRAWPRIMITIVE2 is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_DRAWPRIMITIVE2, and is used to render a primitive.

## Members

### `primType`

Specifies the type of primitive to draw (one of D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP or D3DPT_TRIANGLEFAN).

### `FirstVertexOffset`

Specifies the offset, in bytes, in stream zero of the vertex data. This is in contrast to D3DDP2OP_DRAWPRIMITIVE where the start of the vertex data in the vertex stream is specified by a vertex index rather than an actual byte offset.

### `PrimitiveCount`

Specifies the number of triangles, lines or points to draw for the given primitive.

## Remarks

The vertex data has been transformed by the runtime.

## See also

D3DDP2OP_DRAWPRIMITIVE

D3DDP2OP_DRAWPRIMITIVE2

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2drawprimitive)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)