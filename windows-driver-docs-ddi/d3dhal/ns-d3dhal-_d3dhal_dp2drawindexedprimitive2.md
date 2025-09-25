# _D3DHAL_DP2DRAWINDEXEDPRIMITIVE2 structure

## Description

 DirectX 8.0 and later versions only.

D3DHAL_DRAWINDEXEDPRIMITIVE2 is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_DRAWINDEXEDPRIMITIVE2, and is used to render a primitive using vertex indices.

## Members

### `primType`

Specifies the type of primitive to draw (one of D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP or D3DPT_TRIANGLEFAN).

### `BaseVertexOffset`

Specifies the offset that should be added to each vertex in vertex stream 0 by the various primitives to determine the actual vertex in vertex stream 0. This offset could be negative, but when an index is added to the offset the result is positive.

### `MinIndex`

Specifies the minimum index of a range of vertices that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `NumVertices`

Specifies the number of vertices in a range that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `StartIndexOffset`

Specifies the offset of the first index in the index buffer from which indices are read to draw the primitives.

### `PrimitiveCount`

Specifies the number of triangles, lines or points to draw for the given primitive.

## Remarks

The vertex data has been transformed by the runtime.

As with vertices, the actual indices to use are not passed with the token data, but rather should be read from the currently selected index buffer. See [Index Buffers](https://learn.microsoft.com/windows-hardware/drivers/display/index-buffers) for more details.

## See also

D3DDP2OP_DRAWINDEXEDPRIMITIVE2

[D3DHAL_DP2DRAWINDEXEDPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2drawindexedprimitive2)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)