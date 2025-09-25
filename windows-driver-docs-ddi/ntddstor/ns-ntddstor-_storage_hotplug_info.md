# _STORAGE_HOTPLUG_INFO structure

## Description

The STORAGE_HOTPLUG_INFO structure provides hotplug information for a device.

## Members

### `Size`

Indicates the size, in bytes, of this structure.

### `MediaRemovable`

Specifies whether the media is removable. If set to a nonzero value, the device media is removable. If set to zero, the device media is not removable.

### `MediaHotplug`

Specifies whether the media is lockable. If set to a nonzero value, the device media is not lockable. If set to zero, the device media is lockable.

### `DeviceHotplug`

Specifies whether the device is a hotplug device. If set to a nonzero value, the device is a hotplug device. If set to zero, the device is not a hotplug device.

### `WriteCacheEnableOverride`

Do not use; set the value to **NULL**.

## Remarks

The value of the **Size** member also identifies the version of this structure. New members will be added to this structure in the future. If the value of the **Size** member is **sizeof**(STORAGE_HOTPLUG_INFO), the current version of the structure is the same as the version you compiled with. If the value is not **sizeof**(STORAGE_HOTPLUG_INFO), the current version contains additional members.

Microsoft Windows XP includes support for hotplug devices. A hotplug device refers to a device whose **RemovalPolicy** value displayed in the Device Manager is **ExpectSurpriseRemoval**. To query whether a particular device is a hotplug device, use the [IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_hotplug_info) request. To set the hotplug properties of a device, use the [IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_hotplug_info) request.

In the case of the IOCTL_STORAGE_SET_HOTPLUG_INFO request, the **DeviceHotplug** member of the STORAGE_HOTPLUG_INFO structure determines what action is taken. If the value of that member is nonzero, the value for the device's removal policy in the registry is set to **ExpectSurpriseRemoval** and all levels of caching are disabled. If the value of **DeviceHotplug** is zero, the removal policy is set to **ExpectOrderlyRemoval**, and caching may be selectively enabled.

## See also

[IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_hotplug_info)

[IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_hotplug_info)