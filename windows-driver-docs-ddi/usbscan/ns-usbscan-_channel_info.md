# _CHANNEL_INFO structure

## Description

The CHANNEL_INFO structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_GET_CHANNEL_ALIGN_RQST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_channel_align_rqst).

## Members

### `EventChannelSize`

Maximum packet size for the interrupt transfer pipe.

### `uReadDataAlignment`

Maximum packet size for the bulk IN transfer pipe.

### `uWriteDataAlignment`

Maximum packet size for the bulk OUT transfer pipe.