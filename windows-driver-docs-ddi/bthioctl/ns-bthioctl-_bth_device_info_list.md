# _BTH_DEVICE_INFO_LIST structure

## Description

The BTH_DEVICE_INFO_LIST structure contains output information about all cached, previously
discovered remote devices.

## Members

### `numOfDevices`

The number of devices that have been discovered.

### `deviceList`

An open-ended array of
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structures. Each
structure contains information about a previously discovered remote device.

## Remarks

The
[IOCTL_BTH_GET_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_device_info) call's
output buffer contains the list of all cached, previously discovered remote devices.

The
**numOfDevices** member of the BTH_DEVICE_INFO_LIST structure returns the total number of
BTH_DEVICE_INFO structures available. If the calling driver passes in a smaller buffer, only a portion of
the available structures will be returned.

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info)

[IOCTL_BTH_GET_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_device_info)