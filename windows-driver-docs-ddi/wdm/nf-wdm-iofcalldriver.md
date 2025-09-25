## Description

> [!CAUTION]
> Call the macro [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) instead, that macro is a passthrough call to this function.

Sends an IRP to the driver associated with a specified device object.

## Parameters

### `DeviceObject`

Pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object), representing the target device for the requested I/O operation.

### `Irp`

Pointer to the [**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp).

## Return value

Returns an appropriate [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The following remarks refer to the wrapper IoCallDriver macro but apply to this function as well, since that macro is a simple passthrough to here.

Before calling IoCallDriver, the calling driver must set up the I/O stack location in the IRP for the target driver. For more information, see [Passing IRPs Down the Driver Stack](https://learn.microsoft.com/windows-hardware/drivers/kernel/passing-irps-down-the-driver-stack).

IoCallDriver assigns the *DeviceObject* input parameter to the DeviceObject member of the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure for the driver being called.

An IRP passed in a call to IoCallDriver becomes inaccessible to the higher-level driver, unless the higher-level driver has called [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) to set up an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP. If it has, the IRP input to the IoCompletion routine has its I/O status block set by the lower drivers, and all lower-level drivers' I/O stack locations are filled with zeros.

Drivers for Windows Server 2003, Windows XP, and Windows 2000 must use [PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocalldriver) rather than IoCallDriver to pass power IRPs ([IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power)).

For more information, see [Calling IoCallDriver vs. Calling PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-iocalldriver-versus-calling-pocalldriver).

## See also

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)

[PoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pocalldriver)