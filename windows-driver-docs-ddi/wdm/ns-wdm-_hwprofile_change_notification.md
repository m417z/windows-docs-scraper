# _HWPROFILE_CHANGE_NOTIFICATION structure

## Description

The **HWPROFILE_CHANGE_NOTIFICATION** structure describes an event related to a hardware profile configuration change. The PnP manager sends this structure to a driver that registered a callback routine for notification of **EventCategoryHardwareProfileChange** events.

## Members

### `Version`

Specifies the version of the data structure, currently 1.

### `Size`

Specifies the size of the structure, in bytes including the size of the standard first three members plus the event-specific data.

### `Event`

Specifies a GUID identifying the event: GUID_HWPROFILE_QUERY_CHANGE, GUID_HWPROFILE_CHANGE_COMPLETE, or GUID_HWPROFILE_CHANGE_CANCELLED. The GUIDs are defined in Wdmguid.h.

## Remarks

There is no event-specific data for a hardware-profile-change event.

## See also

[DEVICE_INTERFACE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[PLUGPLAY_NOTIFICATION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_plugplay_notification_header)

[TARGET_DEVICE_REMOVAL_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_removal_notification)