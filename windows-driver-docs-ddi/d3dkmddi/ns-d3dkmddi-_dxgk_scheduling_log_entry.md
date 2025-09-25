# _DXGK_SCHEDULING_LOG_ENTRY structure

## Description

Contains information about a scheduling log entry.

## Members

### `ContextStateChange`

Pointer to a [DXGK_SCHEDULING_LOG_CONTEXT_STATE_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_scheduling_log_context_state_change) structure that contains information about a scheduling log context state change event.

### `ReservedOperationData`

The number of reserved operation data.

### `GpuTimeStamp`

The GPU time stamp.

### `OperationType`

Pointer to a [DXGK_SCHEDULING_LOG_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_scheduling_log_operation) enumeration that contains information about a scheduling log operation.

### `ReservedOperationTypeBits`

The number of reserved operation type bits.

## Remarks

## See also