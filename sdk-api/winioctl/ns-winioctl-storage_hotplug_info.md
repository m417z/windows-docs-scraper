# STORAGE_HOTPLUG_INFO structure

## Description

Provides information about the hotplug information of a device.

## Members

### `Size`

The size of this structure, in bytes. The caller must set this member to
`sizeof(STORAGE_HOTPLUG_INFO)`.

### `MediaRemovable`

If this member is set to a nonzero value, the device media is removable. Otherwise, the device media is not
removable.

### `MediaHotplug`

If this member is set to a nonzero value, the media is not lockable. Otherwise, the device media is
lockable.

### `DeviceHotplug`

If this member is set to a nonzero value, the device is a hotplug device. Otherwise, the device is not a
hotplug device.

### `WriteCacheEnableOverride`

Reserved; set the value to **NULL**.

## Remarks

The value of the **Size** member also identifies the version of this structure, as
members will be added to this structure in the future. If the value of the **Size** member
is `sizeof(STORAGE_HOTPLUG_INFO)`, the current version of the
structure is the same as the version you compiled with. If the value is not
`sizeof(STORAGE_HOTPLUG_INFO)`, then the current version contains
additional members.

A hotplug device refers to a device whose **RemovalPolicy** value displayed in
the Device Manager is **ExpectSurpriseRemoval**. To query whether a particular device is a
hotplug device, use the
[IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_get_hotplug_info) operation.
To set the hotplug properties of a device, use the
[IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_hotplug_info)
operation.

The [IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_hotplug_info)
operation only sets the value of the **DeviceHotplug** member of this structure. If the
value of that member is set, the removal policy of the specified device is set to
**ExpectSurpriseRemoval** and all levels of caching are disabled. If the value of that
member is not set, the removal policy of the specified device is set
to **ExpectOrderlyRemoval**, and caching may be selectively enabled.

## See also

[IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_get_hotplug_info)

[IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_hotplug_info)