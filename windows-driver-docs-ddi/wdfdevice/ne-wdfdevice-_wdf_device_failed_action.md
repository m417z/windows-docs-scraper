# _WDF_DEVICE_FAILED_ACTION enumeration

## Description

[Applies to KMDF and UMDF]

The WDF_DEVICE_FAILED_ACTION enumeration identifies the action that the framework will take when a driver reports an unrecoverable software or hardware failure.

## Constants

### `WdfDeviceFailedUndefined:0`

For internal use only.

### `WdfDeviceFailedAttemptRestart`

Supported in KMDF and starting in UMDF version 2.15. If the device's drivers are not supporting other devices that are plugged into the computer, the I/O manager unloads the drivers. Next, the Plug and Play manager attempts to restart the device by requesting the bus driver to reenumerate its devices. If the bus driver supports reenumeration, your driver will be reloaded, if it was unloaded. If several consecutive restart attempts fail (because the restarted driver again reports an error), the framework stops trying to restart the device.

### `WdfDeviceFailedNoRestart`

If the device's drivers are not supporting other devices on the system, the I/O manager unloads the drivers.

## Remarks

The WDF_DEVICE_FAILED_ACTION enumeration is used as an input argument to [WdfDeviceSetFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetfailed).

Drivers typically specify **WdfDeviceFailedAttemptRestart** if they encounter an unrecoverable software error, because specifying this enumerator reloads the drivers. A driver might specify **WdfDeviceFailedNoRestart** if it encounters an unrecoverable hardware error that affects all of the driver's devices.

For information about specifying **WdfDeviceFailedAttemptRestart** in a UMDF driver, see the Remarks of [WdfDeviceSetFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetfailed).

## See also

[WdfDeviceSetFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetfailed)