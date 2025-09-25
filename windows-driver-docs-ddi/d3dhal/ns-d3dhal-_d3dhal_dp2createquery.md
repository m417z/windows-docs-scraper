# _D3DHAL_DP2CREATEQUERY structure

## Description

 DirectX 9.0 and later versions only.

One or more D3DHAL_DP2CREATEQUERY structures are parsed from the command buffer by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback when the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure's **bCommand** member is set to D3DDP2OP_CREATEQUERY, and are used to create resources for queries.

## Members

### `dwQueryID`

Identifies the query.

### `QueryType`

Specifies a value from the D3DQUERYTYPE enumeration that indicates the query capability for which the driver creates resources.

## Remarks

The runtime uses D3DHAL_DP2CREATEQUERY to identify each query with a unique identifier and a query type. The driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback must process **wPrimitiveCount** D3DHAL_DP2CREATEQUERY structures from the command buffer. The value of **wPrimitiveCount** is specified in the D3DHAL_DP2COMMAND structure. The driver parses these structures and creates resources for the queries that they represent as necessary.

The driver creates resources for the following query types:

* BOOL for D3DQUERYTYPE_EVENT. Before responding with D3DDP2OP_RESPONSEQUERY for an event, the driver must ensure that the graphics processing unit (GPU) is finished processing all [D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation) operations that are related to the event. That is, the driver only responds after the event's ISSUE_END state occurs. The driver must always set the event's BOOL value to **TRUE** when responding.
* DWORD for D3DQUERYTYPE_OCCLUSION. The driver sets this DWORD to the number of pixels for which the z-test passed for all primitives between the begin and end of the query. If the depth buffer is multisampled, the driver determines the number of pixels from the number of samples. However, if the display device is capable of per-multisample z-test accuracy, the conversion to number of pixels should generally be rounded up. An application can then check the occlusion result against 0, to effectively mean "fully occluded". Drivers that convert multisampled quantities to pixel quantities should detect render target multisampling changes and continue to compute the query results appropriately.
* [D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ns-d3d9types-_d3ddevinfo_vcache) structure for D3DQUERYTYPE_VCACHE.

## See also

[D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ns-d3d9types-_d3ddevinfo_vcache)

D3DDP2OP_CREATEQUERY

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2DELETEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2deletequery)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)