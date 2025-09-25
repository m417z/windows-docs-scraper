# _D3DHAL_DP2POINTS structure

## Description

One or more D3DHAL_DP2POINTS structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_POINTS, and are used to render the specified points.

## Members

### `wCount`

Specifies the number of points to render.

### `wVStart`

Specifies the index into the vertex buffer containing coordinate data for the initial point.

## Remarks

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process **wPrimitiveCount** D3DHAL_DP2POINTS structures from the command buffer. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

For each D3DHAL_DP2POINTS structure, [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should sequentially process **wCount** vertices from the vertex buffer. Starting from the vertex buffer offset, the sequence of points rendered is **wVStart**, (**wVStart**+1), ..., (**wVStart**+(**wCount**-1)).

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_POINTS command and two D3DHAL_DP2POINTS structures. The driver should draw a total of seven points using the following vertices from the vertex buffer: v[2], v[3], v[4], v[7], v[8], v[9], v[10].

![Figure showing a command buffer with a D3DDP2OP_POINTS command and two D3DHAL_DP2POINTS structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2pnts.png)

## See also

D3DDP2OP_POINTS

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)