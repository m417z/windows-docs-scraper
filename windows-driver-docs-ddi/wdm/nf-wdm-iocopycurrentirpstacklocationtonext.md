# IoCopyCurrentIrpStackLocationToNext function

## Description

The **IoCopyCurrentIrpStackLocationToNext** routine copies the IRP stack parameters from the current I/O stack location to the stack location of the next-lower driver.

## Parameters

### `Irp` [in, out]

A pointer to the IRP.

## Remarks

A driver calls **IoCopyCurrentIrpStackLocationToNext** to copy the IRP parameters from its stack location to the next-lower driver's stack location.

After calling this routine, a driver typically sets an I/O completion routine with [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) before passing the IRP to the next-lower driver with [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver). Drivers that pass on their IRP parameters but do not set an I/O completion routine should call [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) instead of this routine.

If your driver calls **IoSkipCurrentIrpStackLocation**, be careful not to modify the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure in a way that could unintentionally affect the lower driver or the system's behavior with respect to that driver. In particular, your driver should not modify the **IO_STACK_LOCATION** structure's **Parameters** union, and should not call the [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending) routine.

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)