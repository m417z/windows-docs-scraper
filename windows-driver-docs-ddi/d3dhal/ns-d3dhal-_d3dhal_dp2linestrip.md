# _D3DHAL_DP2LINESTRIP structure

## Description

One D3DHAL_DP2LINESTRIP structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_LINESTRIP, and is used to render the specified connected line segments.

## Members

### `wVStart`

Specifies the index into the vertex buffer containing coordinate data for the initial vertex of the line strip.

## Remarks

One D3DHAL_DP2LINESTRIP structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should sequentially process a total of (**wPrimitiveCount** + 1) vertices from the vertex buffer. Starting from the vertex buffer offset, the sequence of lines rendered is (**wVStart**, **wVStart** + 1), (**wVStart** + 1, **wVStart** + 2), (**wVStart** + 2, **wVStart** + 3), ..., (**wVStart** + (**wPrimitiveCount** - 1), **wVStart** + **wPrimitiveCount**). The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_LINESTRIP command and one D3DHAL_DP2LINESTRIP structure. The driver should draw three connected lines using the following four vertices from the vertex buffer: (v[4], v[5]), (v[5], v[6]), (v[6], v[7]).

![Figure showing a command buffer with a D3DDP2OP_LINESTRIP command and one D3DHAL_DP2LINESTRIP structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2lstr.png)

## See also

D3DDP2OP_LINESTRIP

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)