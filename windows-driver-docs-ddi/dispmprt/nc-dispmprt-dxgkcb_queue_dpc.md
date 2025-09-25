# DXGKCB_QUEUE_DPC callback function

## Description

The **DxgkCbQueueDpc** function queues a deferred procedure call (DPC) for execution at IRQL DISPATCH_LEVEL.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

## Return value

**DxgkCbQueueDpc** returns **TRUE** if the DPC is successfully queued; otherwise it returns **FALSE**.

## Remarks

This function queues a DPC object for the display miniport and calls the [DxgkDdiDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpc_routine) function when the interrupt service routine (ISR) requests it.

There can only be one callback to this function scheduled per device at any one time. If a callback is already scheduled for a device, a second call to **DxgkCbQueueDpc** will not have any effect and will return **FALSE**.

For more information on the use of this function, see these topics:

* [Submitting a Command Buffer](https://learn.microsoft.com/windows-hardware/drivers/display/submitting-a-command-buffer)
* [Windows Display Driver Model (WDDM) Operation Flow](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow)

## See also

[DxgkCbQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc)

[DxgkDdiDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpc_routine)