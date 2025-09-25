# IoRequestDpc function

## Description

The **IoRequestDpc** routine queues a driver-supplied [DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) routine to complete interrupt-driven I/O processing at a lower IRQL.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for which the request that caused the interrupt is being processed.

### `Irp` [in]

Pointer to the current IRP for the specified device.

### `Context` [in]

Pointer to a driver-determined context to be passed to the DPC routine.

## Remarks

Callers of **IoRequestDpc** must be running at DIRQL.

Drivers call **IoRequestDpc** from an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine. Because of this, **IoRequestDpc** runs at the DIRQL value that was specified by *SynchronizeIrql* when the driver called [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt). However, it is also possible to queue a DPC at any IRQL >= DISPATCH_LEVEL by using the **Ke*Xxx*Dpc** routines. For more information, see [Which Type of DPC Should You Use?](https://learn.microsoft.com/windows-hardware/drivers/kernel/which-type-of-dpc-should-you-use-)

## See also

[IoInitializeDpcRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializedpcrequest)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)