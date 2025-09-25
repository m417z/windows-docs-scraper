# _D3DHAL_CLIPPEDTRIANGLEFAN structure

## Description

 DirectX 8.0 and later versions only.

One or more D3DHAL_CLIPPEDTRIANGLEFAN structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_CLIPPEDTRIANGLEFAN, and are used to render clipped triangle fans.

## Members

### `FirstVertexOffset`

Specifies the byte offset into stream 0 of the start of the vertex data (not the index of the vertex).

### `dwEdgeFlags`

Specifies a bitmask that identifies what edges are to be drawn when rendering wire frame (to prevent the drawing of edges introduced by clipping). For more information about this bitmask, see the Remarks section of the [D3DHAL_DP2TRIANGLEFAN_IMM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglefan_imm) structure.

### `PrimitiveCount`

Specifies the number of triangles in the given triangle fan.

## See also

D3DDP2OP_CLIPPEDTRIANGLEFAN

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)