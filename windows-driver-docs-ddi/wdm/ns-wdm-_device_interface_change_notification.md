# _DEVICE_INTERFACE_CHANGE_NOTIFICATION structure

## Description

The **DEVICE_INTERFACE_CHANGE_NOTIFICATION** structure describes a device interface that has been enabled (arrived) or disabled (removed). The PnP manager sends this structure to a driver that registered a callback routine for notification of **EventCategoryDeviceInterfaceChange** events.

## Members

### `Version`

Specifies the version of the data structure, currently 1.

### `Size`

Specifies the size of the structure, in bytes, including the size of the standard first three members plus the event-specific data.

### `Event`

Specifies a GUID identifying the event: GUID_DEVICE_INTERFACE_ARRIVAL or GUID_DEVICE_INTERFACE_REMOVAL. The GUIDs are defined in Wdmguid.h.

### `InterfaceClassGuid`

Specifies the class of the device interface that has just been enabled or disabled.

### `SymbolicLinkName`

Pointer to a Unicode string that contains the name of the symbolic link for the device interface.

## Remarks

This structure is allocated from paged memory.

## See also

[HWPROFILE_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_hwprofile_change_notification)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[PLUGPLAY_NOTIFICATION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_plugplay_notification_header)

[TARGET_DEVICE_REMOVAL_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_removal_notification)