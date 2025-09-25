# _D3DHAL_DP2ISSUEQUERY structure

## Description

 DirectX 9.0 and later versions only.

One or more D3DHAL_DP2ISSUEQUERY structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_ISSUEQUERY, and are used to query for various types of information.

## Members

### `dwQueryID`

Identifies the query for which the driver asynchronously provides information.

### `dwFlags`

Specifies the state of the query. This member can contain one or more of the following flags:

|Value|Meaning|
|---|---|
|D3DISSUE_BEGIN (1 << 1)|Starts building the query. The runtime does not request query data while in this state.|
|D3DISSUE_END (1 << 0)|Transitions the state to subsignaled. Results of the query are not available until the state transitions to signaled.|

The driver can ignore query requests with **dwFlags** set to 0.

## Remarks

The runtime uses D3DHAL_DP2ISSUEQUERY to identify each query that the driver must process. The driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback must process **wPrimitiveCount** D3DHAL_DP2ISSUEQUERY structures from the command buffer. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure. The driver parses these structures and retrieves information associated with the queries that they represent.

## See also

D3DDP2OP_ISSUEQUERY

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createquery)

[D3DHAL_DP2RESPONSEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2responsequery)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)