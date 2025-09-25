# IoSetNextIrpStackLocation function

## Description

The **IoSetNextIrpStackLocation** routine sets the IRP stack location in a driver-allocated IRP to that of the caller.

## Parameters

### `Irp` [in, out]

Pointer to the IRP whose stack location is to be set.

## Remarks

In general, this routine is seldom used by drivers. It is primarily used by drivers that require their own stack location in an IRP that they have allocated, on their own, to send to another driver.

**IoSetNextIrpStackLocation** is generally not needed because either:

* The driver received the IRP it is passing from another, higher-level driver, and so it already owns a stack location,
* Or, the driver allocated the IRP but does not need its own stack location because it can keep everything that it needs in a context block whose address can be passed to its *IoCompletion* routine.

Care should be taken if this routine is called, especially when allocating the IRP with **IoAllocateIrp** or **IoMakeAssociatedIrp**. The writer of the allocating driver must remember that a caller-specific stack location is not included in the number of stack locations required by the lower-level drivers to which it sends IRPs with **IoCallDriver**. A driver must explicitly specify a stack location for itself in its call to **IoAllocateIrp** or **IoMakeAssociatedIrp** if it calls **IoSetNextIrpStackLocation** with the IRP returned by either routine.

A driver cannot call **IoSetNextIrpStackLocation** with any IRP it allocates by calling **IoBuildAsynchronousFsdRequest**, **IoBuildDeviceIoControlRequest**, or **IoBuildSynchronousFsdRequest**.

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)