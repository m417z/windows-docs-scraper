# _D3DHAL_DP2RESPONSEQUERY structure

## Description

 DirectX 9.0 and later versions only.

One or more D3DHAL_DP2RESPONSEQUERY structure are parsed from the response buffer by the runtime after the runtime calls the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback. The driver sets the [D3DHAL_DP2RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2response) structure's **bCommand** member to D3DDP2OP_RESPONSEQUERY to indicate that responses to previously issued queries are available in the response buffer.

## Members

### `dwQueryID`

Identifies the query for which response data is available.

### `dwSize`

Specifies the size, in bytes, of the query information that the driver returns to the runtime.

## Remarks

The runtime uses the D3DDP2OP_ISSUEQUERY command to request that the driver process queries. The driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback should process **wPrimitiveCount** [D3DHAL_DP2ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2issuequery) query structures from the command buffer. The value of **wPrimitiveCount**  is specified in the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure. The driver parses these query structures and translates them to its hardware specific commands.

If previously submitted queries using the D3DDP2OP_ISSUEQUERY operation completed, the driver sets the size of the response buffer in the dwErrorOffset member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure and sets the **ddrval** member of D3DHAL_DRAWPRIMITIVES2DATA to D3D_OK for successful completion. The driver also overwrites the incoming command buffer with the outgoing response buffer. Each D3DHAL_DP2RESPONSEQUERY in the response buffer is followed by the following data related to the query:

* BOOL for D3DQUERYTYPE_EVENT. Before responding with D3DDP2OP_RESPONSEQUERY for an event, the driver must ensure that the graphics processing unit (GPU) is finished processing all [D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation) operations that are related to the event. That is, the driver only responds after the event's ISSUE_END state occurs. The driver must always set the event's BOOL value to **TRUE** when responding.
* DWORD for D3DQUERYTYPE_OCCLUSION. The driver sets this DWORD to the number of pixels for which the z-test passed for all primitives between the begin and end of the query. If the depth buffer is multisampled, the driver determines the number of pixels from the number of samples. However, if the display device is capable of per-multisample z-test accuracy, the conversion to number of pixels should generally be rounded up. An application can then check the occlusion result against 0, to effectively mean "fully occluded". Drivers that convert multisampled quantities to pixel quantities should detect render target multisampling changes and continue to compute the query results appropriately.
* [D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ns-d3d9types-_d3ddevinfo_vcache) structure for D3DQUERYTYPE_VCACHE.

The runtime parses the returned response buffer and updates its internal data structures.

## See also

[D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ns-d3d9types-_d3ddevinfo_vcache)

D3DDP2OP_ISSUEQUERY

D3DDP2OP_RESPONSEQUERY

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2issuequery)

[D3DHAL_DP2RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2response)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)