# _DRV_VERSION structure

## Description

The DRV_VERSION structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_GET_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_version).

## Members

### `major`

Major version number.

### `minor`

Minor version number.

### `internal`

Internal, vendor-specific version number.