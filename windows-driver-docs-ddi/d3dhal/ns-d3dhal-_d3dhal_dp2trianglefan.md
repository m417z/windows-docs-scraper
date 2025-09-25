# _D3DHAL_DP2TRIANGLEFAN structure

## Description

One D3DHAL_DP2TRIANGLEFAN structure is parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_TRIANGLEFAN, and is used to render a triangle fan.

## Members

### `wVStart`

Specifies the index into the vertex buffer containing coordinate data for the initial vertex of the triangle fan.

## Remarks

One D3DHAL_DP2TRIANGLEFAN structure follows the D3DHAL_DP2COMMAND structure in the command buffer.

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) should process a total of **wPrimitiveCount** + 2 vertices from the vertex buffer, three vertices per triangle, rendering **wPrimitiveCount** triangles. Starting from the vertex buffer offset, the sequence of triangles rendered is (**wVStart**  + 1, **wVStart**  + 2, **wVStart** ), (**wVStart**  + 2, **wVStart**  + 3, **wVStart** ),..., (**wVStart**  + **wPrimitiveCount**, **wVStart** +**wPrimitiveCount** + 1, **wVStart** ). The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure.

The following figure shows a portion of a sample command buffer containing a D3DDP2OP_TRIANGLEFAN command and a D3DHAL_DP2TRIANGLEFAN structure. The driver should process six vertices from the vertex buffer, rendering a fan with four triangles defined by (v[3], v[4], v[2]), (v[4], v[5], v[2]), (v[5], v[6], v[2]), (v[6], v[7], v[2]).

![Figure showing a command buffer with a D3DDP2OP_TRIANGLEFAN command and a D3DHAL_DP2TRIANGLEFAN structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/images/dp2tfan.png)

## See also

D3DDP2OP_TRIANGLEFAN

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)