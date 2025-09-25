# _D3DHAL_DP2INDEXEDTRIANGLELIST2 structure

## Description

One or more D3DHAL_DP2INDEXEDTRIANGLELIST2 structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_INDEXEDTRIANGLELIST2, and are used to render a sequence of unconnected triangles using vertex indices.

## Members

### `wV1`

Specifies the index to the vertex buffer location containing coordinate data for the first vertex of the triangle.

### `wV2`

Specifies the index to the vertex buffer location containing coordinate data for the second vertex of the triangle.

### `wV3`

Specifies the index to the vertex buffer location containing coordinate data for the third vertex of the triangle.

## Remarks

The D3DHAL_DP2INDEXEDTRIANGLELIST2 structure specifies unconnected triangles to render with a vertex buffer. The vertex indexes are specified by *wV1*, *wV2*, and *wV3*. All edges are visible. The number of triangles to render (that is, the number of D3DHAL_DP2INDEXEDTRIANGLELIST2 structures to process) is specified by the **wPrimitiveCount** field of D3DHAL_DP2COMMAND. All indexes are relative to a vertex whose index is *wVStart* from [D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex). The sequence in the command stream is D3DHAL_DP2COMMAND followed by D3DHAL_DP2STARTVERTEX followed by **wPrimitiveCount**D3DHAL_DP2INDEXEDTRIANGLELIST2 structures.

The [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback parses D3DHAL_DP2INDEXEDTRIANGLELIST2 structure(s) from the command buffer and renders the triangles using vertex indexes when D3DHAL_DP2COMMAND is D3DDP2OP_INDEXEDTRIANGLELIST2. A D3DHAL_DP2STARTVERTEX structure immediately follows the D3DHAL_DP2COMMAND in the command stream. This allows a base index to be specified for all the indexes that follow it. Thus triangles can be easily relocated and no flags are necessary to specify the triangle edges as is the case with D3DDP2OP_INDEXEDTRIANGLELIST.

## See also

D3DDP2OP_INDEXEDTRIANGLELIST

D3DDP2OP_INDEXEDTRIANGLELIST2

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2STARTVERTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2startvertex)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)