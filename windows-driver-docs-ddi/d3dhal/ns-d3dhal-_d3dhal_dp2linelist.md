# _D3DHAL_DP2LINELIST structure

## Description

One D3DHAL_DP2LINELIST structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_LINELIST, and is used to render unconnected line segments.

## Members

### `wVStart`

Specifies the index into the vertex buffer containing coordinate data for the initial vertex of the line list.

## Remarks

One D3DHAL_DP2LINELIST structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should sequentially process a total of **wPrimitiveCount** * 2 vertices from the vertex buffer, two vertices per line, rendering a total of **wPrimitiveCount** lines. Starting from the vertex buffer offset, the sequence of lines rendered is (**wVStart**, **wVStart** + 1), (**wVStart** + 2, **wVStart** + 3),..., (**wVStart** + (**wPrimitiveCount** -1 ) * 2, **wVStart** + (**wPrimitiveCount** * 2 - 1)). The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_LINELIST command and one D3DHAL_DP2LINELIST structure. The driver should draw three lines using the following six vertices from the vertex buffer: (v[0], v[1]), (v[2], v[3]), (v[4], v[5]).

![Figure showing a command buffer with a D3DDP2OP_LINELIST command and one D3DHAL_DP2LINELIST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2lnlst.png)

## See also

D3DDP2OP_LINELIST

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)