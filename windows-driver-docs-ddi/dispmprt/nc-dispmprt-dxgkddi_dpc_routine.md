# DXGKDDI_DPC_ROUTINE callback function

## Description

The *DxgkDdiDpcRoutine* function is called back at IRQL DISPATCH_LEVEL after the display miniport driver calls [DxgkCbQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc).

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

## Remarks

Only one deferred procedure call (DPC) can be scheduled (at a given time) for a given display adapter.

If the display miniport driver is supporting several display adapters, the *DxgkDdiDpcRoutine* might be called in a reentrant fashion. That is, while *DxgkDdiDpcRoutine* is executing on one processor on behalf of a particular display adapter, it could be called again on another processor on behalf of a different display adapter.

## See also

[DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine)