# _PLUGPLAY_NOTIFICATION_HEADER structure

## Description

A **PLUGPLAY_NOTIFICATION_HEADER** structure is included at the beginning of each PnP notification structure, such as a [DEVICE_INTERFACE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification) structure.

## Members

### `Version`

Specifies the version of the data structure, currently set to 1.

### `Size`

Specifies the size of the structure, in bytes.

### `Event`

Specifies a GUID identifying the event.

## Remarks

Drivers can cast a PnP notification structure to this type to access the **Event** field and identify the exact type of the structure.

## See also

[DEVICE_INTERFACE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification)

[HWPROFILE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_hwprofile_change_notification)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)

[TARGET_DEVICE_REMOVAL_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_removal_notification)