# _USBSCAN_PIPE_CONFIGURATION structure

## Description

The USBSCAN_PIPE_CONFIGURATION structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_GET_PIPE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_pipe_configuration).

## Members

### `NumberOfPipes`

The number of transfer pipes supported for the device.

### `PipeInfo`

Pointer to a **NumberOfPipes**-sized array of [USBSCAN_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_pipe_information) structures.