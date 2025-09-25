# _D3DHAL_DP2DRAWINDEXEDPRIMITIVE structure

## Description

 DirectX 8.0 and later versions only.

D3DHAL_DRAWINDEXEDPRIMITIVE is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_DRAWINDEXEDPRIMITIVE, and is used to render a primitive using vertex indices.

## Members

### `primType`

Specifies the type of primitive to draw (one of D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP or D3DPT_TRIANGLEFAN).

### `BaseVertexIndex`

Specifies the amount that should be added to each index referenced by the various primitives to determine the actual index of the vertex elements in each vertex stream.

**DirectX 8.1 and earlier versions only.**

Specified using a DWORD.

**DirectX 9.0 and later versions only.**

Specified using an INT.

### `MinIndex`

Specifies the minimum index of a range of vertices that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `NumVertices`

Specifies the number of vertices in a range that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `StartIndex`

Specifies the first index in the index buffer from which indices are read to draw the primitives.

### `PrimitiveCount`

Specifies the number of triangles, lines or points to draw for the given primitive.

## Remarks

The vertex data can be untransformed (if the hardware supports hardware vertex processing) or transformed if the application supplied data in that form to the runtime.

As with vertices, the actual indices to use are not passed with the token data, but rather should be read from the currently selected index buffer. See [Index Buffers](https://learn.microsoft.com/windows-hardware/drivers/display/index-buffers) for more details.

## See also

D3DDP2OP_DRAWINDEXEDPRIMITIVE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2DRAWINDEXEDPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2drawindexedprimitive2)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)