# KeIpiGenericCall function

## Description

The **KeIpiGenericCall** routine causes the specified routine to run on all processors simultaneously.

## Parameters

### `BroadcastFunction` [in]

Pointer to an [IpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kipi_broadcast_worker) routine. This routine is run on every processor simultaneously.

### `Context` [in]

Specifies the value to pass to *IpiGenericCall* when it is called.

## Return value

**KeIpiGenericCall** returns the value that [IpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kipi_broadcast_worker) returns on the source processor (the processor that called **KeIpiGenericCall**).

## Remarks

When a driver calls **KeIpiGenericCall**, the system interrupts every processor and raises the IRQL to IPI_LEVEL (interprocessor interrupt level). Each processor spins on a barrier until all processors have reached the barrier; then, all processors begin calling [IpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kipi_broadcast_worker). **KeIpiGenericCall** waits for all calls to *IpiGenericCall* to complete before returning.

## See also

[IpiGenericCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kipi_broadcast_worker)