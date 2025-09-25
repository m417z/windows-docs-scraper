# EVT_WDF_DEVICE_SHUTDOWN_NOTIFICATION callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceShutdownNotification* event callback function notifies the driver that the system is about to lose its power.

## Parameters

### `Device` [in]

A handle to a framework device object that the driver initialized by calling [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate).

## Remarks

To register an *EvtDeviceShutdownNotification* event callback function, a driver must call [WdfControlDeviceInitSetShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitsetshutdownnotification). Only drivers that create control device objects can register this callback function.

The framework calls a driver's *EvtDeviceShutdownNotification* event callback function if the user is about to turn off the computer, or if the computer suddenly loses its power and an emergency power supply, such as an uninterruptible power supply (UPS), is available to safely turn off the computer.

For more information about control device objects and the *EvtDeviceShutdownNotification* callback function see [Using Control Device Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

## See also

[WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate)

[WdfControlDeviceInitSetShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitsetshutdownnotification)