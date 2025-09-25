# _D3DHAL_DP2DELETEQUERY structure

## Description

 DirectX 9.0 and later versions only.

One or more D3DHAL_DP2DELETEQUERY structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_DELETEQUERY, and are used to release resources for queries.

## Members

### `dwQueryID`

Identifies the query for which the driver releases resources.

## Remarks

The runtime uses D3DHAL_DP2DELETEQUERY to identify each query. The driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback must process **wPrimitiveCount** D3DHAL_DP2DELETEQUERY structures from the command buffer. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure. The driver parses these structures and releases resources for the queries that they represent.

## See also

D3DDP2OP_DELETEQUERY

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createquery)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)