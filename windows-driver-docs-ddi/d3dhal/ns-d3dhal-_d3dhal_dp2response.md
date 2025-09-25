# _D3DHAL_DP2RESPONSE structure

## Description

 DirectX 9.0 and later versions only.

One or more D3DHAL_DP2RESPONSE structures are parsed from the response buffer that the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback returns to the runtime. Each structure specifies the availability of responses to previously issued queries.

## Members

### `bCommand`

Specifies a response token. This member can be either D3DDP2OP_RESPONSECONTINUE or D3DDP2OP_RESPONSEQUERY of the [D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation) enumerated type.

### `bReserved`

Reserved for system use and should be ignored by the driver.

### `wStateCount`

Specifies the number of responses (that is, the number of [D3DHAL_DP2RESPONSEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2responsequery) structures) that follow this D3DHAL_DP2RESPONSE structure. If the driver sets **bCommand** to D3DDP2OP_RESPONSECONTINUE, the driver should set this member to zero. However, the runtime ignores this member when **bCommand** is set to D3DDP2OP_RESPONSECONTINUE; this member is only valid when the driver sets **bCommand** to D3DDP2OP_RESPONSEQUERY.

### `dwTotalSize`

Specifies the total size, in bytes, of the responses associated with this D3DHAL_DP2RESPONSE structure. The driver also includes the size of this D3DHAL_DP2RESPONSE structure in the total size to let the runtime skip over this D3DHAL_DP2RESPONSE structure when parsing the response buffer.

## See also

D3DDP2OP_RESPONSECONTINUE

D3DDP2OP_RESPONSEQUERY

[D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation)

[D3DHAL_DP2RESPONSEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2responsequery)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)