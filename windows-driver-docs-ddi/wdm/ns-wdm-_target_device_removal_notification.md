# _TARGET_DEVICE_REMOVAL_NOTIFICATION structure

## Description

The **TARGET_DEVICE_REMOVAL_NOTIFICATION** structure describes a device-removal event. The PnP manager sends this structure to a driver that registered a callback routine for notification of **EventCategoryTargetDeviceChange** events.

## Members

### `Version`

Specifies the version of the data structure, currently set to 1.

### `Size`

Specifies the size of the structure, in bytes, including the size of the standard first three members plus the event-specific data.

### `Event`

Specifies a GUID identifying the event: GUID_TARGET_DEVICE_QUERY_REMOVE, GUID_TARGET_DEVICE_REMOVE_COMPLETE, or GUID_TARGET_DEVICE_REMOVE_CANCELLED. These GUIDs are defined in Wdmguid.h.

### `FileObject`

Pointer to a file object for the device.

## See also

[DEVICE_INTERFACE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification)

[HWPROFILE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_hwprofile_change_notification)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)