# _D3DHAL_DP2TRIANGLELIST structure

## Description

One D3DHAL_DP2TRIANGLELIST structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_TRIANGLELIST, and is used to render the specified unconnected triangles.

## Members

### `wVStart`

Specifies the offset into the vertex buffer containing coordinate data for the initial vertex of the triangle list

## Remarks

One D3DHAL_DP2TRIANGLELIST structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should sequentially process a total of **wPrimitiveCount** * 3 vertices from the vertex buffer, three vertices per triangle, rendering **wPrimitiveCount** triangles. Starting from the vertex buffer offset, the sequence of triangles rendered is (**wVStart**, **wVStart** + 1, **wVStart** + 2), (**wVStart** + 3, **wVStart** + 4, **wVStart** + 5),..., (**wVStart** + (**wPrimitiveCount** - 1) * 3, **wVStart** + **wPrimitiveCount** * 3 - 2, **wVStart** + **wPrimitiveCount** * 3 - 1). The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_TRIANGLELIST command and one D3DHAL_DP2TRIANGLELIST structure. The driver should draw two triangles using the following six vertices from the vertex buffer: (v[2], v[3], v[4]), (v[5], v[6], v[7]).

![Figure showing a command buffer with a D3DDP2OP_TRIANGLELIST command and one D3DHAL_DP2TRIANGLELIST structure ](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tlist.png)

## See also

D3DDP2OP_TRIANGLELIST

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)