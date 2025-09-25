# _D3DHAL_DP2COMMAND structure

## Description

One or more D3DHAL_DP2COMMAND structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback, which uses the information it receives to draw one or more primitives. Each structure specifies either a primitive to draw or a state change to process.

## Members

### `bCommand`

Specifies a primitive to draw or a state change to process. This member can be one of the [D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation) enumerated values.

### `bReserved`

Reserved for system use and should be ignored by the driver.

### `wPrimitiveCount`

Specifies the number of primitives to process. This member is valid when **bCommand** is not either of D3DDP2OP_RENDERSTATE or D3DDP2OP_TEXTURESTAGESTATE.

### `wStateCount`

Specifies the number of state changes to process. This member is valid when **bCommand** is one of D3DDP2OP_RENDERSTATE or D3DDP2OP_TEXTURESTAGESTATE.

## See also

D3DDP2OP_RENDERSTATE

D3DDP2OP_TEXTURESTAGESTATE

[D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)