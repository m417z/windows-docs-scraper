# EVT_WDF_DEVICE_USAGE_NOTIFICATION callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceUsageNotification* event callback function informs the driver when a device is being used for special files.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `NotificationType` [in]

A [WDF_SPECIAL_FILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type)-typed value that identifies the type of special file that the system is storing on the specified device.

### `IsInNotificationPath` [in]

A Boolean value which, if **TRUE**, indicates that the system has starting using the special file and, if **FALSE**, indicate that the system as finished using the special file.

## Remarks

To register an *EvtDeviceUsageNotification* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

Your driver must provide an *EvtDeviceUsageNotification* callback function only if must provide driver-specific handling of special files.

For more information about special files, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).