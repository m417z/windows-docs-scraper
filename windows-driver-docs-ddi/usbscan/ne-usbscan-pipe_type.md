# PIPE_TYPE enumeration

## Description

The **PIPE_TYPE** data type is used as input to the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function, if the I/O control code is [IOCTL_CANCEL_IO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_cancel_io) or [IOCTL_RESET_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_reset_pipe). An interrupt pipe, a bulk IN pipe, and a bulk OUT pipe are associated with each device handle supplied to **DeviceIoControl**. The specified PIPE_TYPE value indicates on which of these pipes the operation should be performed, as indicated in the following table.

## Constants

### `EVENT_PIPE`

The operation should be performed on the interrupt pipe.

### `READ_DATA_PIPE`

The operation should be performed on the bulk IN pipe.

### `WRITE_DATA_PIPE`

The operation should be performed on the bulk OUT pipe.

### `ALL_PIPE`

The operation should be performed on *all* transfer pipes (not just the pipes associated with the device handle supplied to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)).