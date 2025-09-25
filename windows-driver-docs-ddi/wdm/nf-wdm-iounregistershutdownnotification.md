# IoUnregisterShutdownNotification function

## Description

The **IoUnregisterShutdownNotification** routine removes a registered driver from the shutdown notification queue.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's device object.

## Remarks

**IoUnregisterShutdownNotification** can be called by a driver only if that driver previously called [IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification) or [IoRegisterLastChanceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterlastchanceshutdownnotification) with the given *DeviceObject*. This routine is usually called from a driver's [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine.

Calling **IoUnregisterShutdownNotification** cancels all shutdown notifications that have been registered for the given *DeviceObject*.

## See also

[IoRegisterLastChanceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterlastchanceshutdownnotification)

[IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification)