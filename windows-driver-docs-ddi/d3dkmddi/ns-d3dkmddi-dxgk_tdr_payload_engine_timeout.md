## Description

The **DXGK_TDR_PAYLOAD_ENGINE_TIMEOUT** structure contains the payload for a [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) call when **TdrType** is **DXGK_TDR_TYPE_ENGINE_TIMEOUT**.

## Members

### `NodeOrdinal`

[in] Node ordinal for the engine being reset.

### `EngineOrdinal`

[in] Engine ordinal for the engine being reset.

### `LastHwCompletedFenceId`

[in] For engines not using the hardware scheduling model, the last fence ID completed by the GPU.

### `LastHwSubmittedFenceId`

[in] For engines not using the hardware scheduling model, the last fence ID submitted to the GPU.

### `NumberOfPendingSuspendRequests`

[in] For engines using the hardware scheduling model, the number of outstanding context suspend requests at the time of the TDR.

### `NumberOfReadyInteractiveHwQueues`

[in] For engines using the hardware scheduling model, the number of ready interactive hardware queues in flight at the time of the TDR.

### `hContext`

[out] Handle of the context that KMD believes has timed out. If KMD couldn't reliably determine which text timed out, it should leave **hContext** set to NULL.

## Remarks

For more information, see [TDR debuggability improvements](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-debuggability-improvements).

## See also

[**DXGK_TDR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_tdr_type)

[**DXGKARG_COLLECTDBGINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_collectdbginfo2)

[**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2)