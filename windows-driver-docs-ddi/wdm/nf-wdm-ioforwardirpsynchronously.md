# IoForwardIrpSynchronously function

## Description

The **IoForwardIrpSynchronously** routine sends an IRP to a specified driver and waits for that driver to complete the IRP.

## Parameters

### `DeviceObject` [in]

Specifies the device object of the driver to which the IRP is sent.

### `Irp` [in]

Specifies the IRP to send.

## Return value

**IoForwardIrpSynchronously** returns **TRUE** if the IRP is sent successfully. Otherwise, it returns **FALSE**.

## Remarks

Use the **IoForwardIrpSynchronously** routine to synchronously forward the current IRP to the next driver in the stack. (To asynchronously forward the IRP, use the [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext), [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), and [IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) routines.)

The **IoForwardIrpSynchronously** routine copies the current stack location to the next stack location. That stack location is then used as the current stack location by the driver specified in *DeviceObject*. If no next stack location is available, the routine returns **FALSE**. If the routine returns **TRUE**, then the IRP has been sent to the specified driver, and that driver has completed its processing of this IRP.

## See also

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)