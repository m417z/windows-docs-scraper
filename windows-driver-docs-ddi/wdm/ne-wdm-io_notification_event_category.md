# IO_NOTIFICATION_EVENT_CATEGORY enumeration

## Description

Specifies the category of PnP event for which the callback routine is being registered. Used in [**IoRegisterPlugPlayNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification).

## Constants

### `EventCategoryReserved`

Reserved for system use.

### `EventCategoryHardwareProfileChange`

PnP events in this category include query-change (GUID_HWPROFILE_QUERY_CHANGE), change-complete (GUID_HWPROFILE_CHANGE_COMPLETE), and change-cancel (GUID_HWPROFILE_CHANGE_CANCELLED) of a hardware profile.

### `EventCategoryDeviceInterfaceChange`

PnP events in this category include the arrival (enabling) of a new instance of a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) (GUID_DEVICE_INTERFACE_ARRIVAL), or the removal (disabling) of an existing device interface instance (GUID_DEVICE_INTERFACE_REMOVAL).

### `EventCategoryTargetDeviceChange`

PnP events in this category include events related to removing a device: the device's drivers received a query-remove IRP (GUID_TARGET_DEVICE_QUERY_REMOVE), the drivers completed a remove IRP (GUID_TARGET_DEVICE_REMOVE_COMPLETE), or the drivers received a cancel-remove IRP (GUID_TARGET_DEVICE_REMOVE_CANCELLED). This category is also used for custom notification events.

### `EventCategoryKernelSoftRestart`

Reserved for system use.

## Remarks

## See also

[**IoRegisterPlugPlayNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)