# _WDF_DEVICE_SHUTDOWN_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_DEVICE_SHUTDOWN_FLAGS** enumeration defines flags that identify types of shutdown notifications that a driver can receive.

## Constants

### `WdfDeviceShutdown:0x01`

The driver is notified when the system is losing its power, but before file systems are flushed.

### `WdfDeviceLastChanceShutdown:0x02`

The driver is notified when the system is losing its power, and after all file systems have been flushed.

## Remarks

The **WDF_DEVICE_SHUTDOWN_FLAGS** enumeration is used as an input parameter to [WdfControlDeviceInitSetShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitsetshutdownnotification).

## See also

[WdfControlDeviceInitSetShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitsetshutdownnotification)