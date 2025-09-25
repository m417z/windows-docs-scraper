# _D3DHAL_DP2STARTVERTEX structure

## Description

A D3DHAL_DP2STARTVERTEX structure follows certain [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structures in the command buffer, and indicates the offset in the vertex buffer for the first vertex to use in [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `wVStart`

Specifies an additional offset to be added to any index used for determining the location of vertices in the vertex buffer (in the case of indexed primitives).

## Remarks

A D3DHAL_DP2STARTVERTEX structure follows a D3DHAL_DP2COMMAND structure in the command buffer when the **bCommand** member of D3DHAL_DP2COMMAND is one of the following values:

* D3DDP2OP_INDEXEDLINELIST2
* D3DDP2OP_INDEXEDLINESTRIP
* D3DDP2OP_INDEXEDTRIANGLELIST2
* D3DDP2OP_INDEXEDTRIANGLESTRIP
* D3DDP2OP_INDEXEDTRIANGLEFAN

The first vertex of such primitives is located (**wVStart** + **dwVertexOffset**) bytes from the beginning of the vertex buffer, where **dwVertexOffset** is a member of [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data).

## See also

D3DDP2OP_INDEXEDLINELIST2

D3DDP2OP_INDEXEDLINESTRIP

D3DDP2OP_INDEXEDTRIANGLEFAN

D3DDP2OP_INDEXEDTRIANGLELIST2

D3DDP2OP_INDEXEDTRIANGLESTRIP

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)