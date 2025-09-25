# EVT_WDF_DEVICE_USAGE_NOTIFICATION_EX callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceUsageNotificationEx* event callback function determines whether a device can support a special file type.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `NotificationType` [in]

A [WDF_SPECIAL_FILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type)-typed value that identifies the type of special file that the system is storing on the specified device.

### `IsInNotificationPath` [in]

A Boolean value which, if **TRUE**, indicates that the system has starting using the special file and, if **FALSE**, indicates that the system has finished using the special file.

## Return value

If the driver determines that the device can support the special file, the *EvtDeviceUsageNotificationEx* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

If your driver must provide driver-specific handling of special files, you must provide either an *EvtDeviceUsageNotificationEx* or an [EvtDeviceUsageNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification) event callback function. Do not provide both callback functions.

To register an *EvtDeviceUsageNotificationEx* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver's *EvtDeviceUsageNotificationEx* callback function returns a failure status, the framework propagates failure to other stacks that it may have notified earlier.

For more information about special files, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).