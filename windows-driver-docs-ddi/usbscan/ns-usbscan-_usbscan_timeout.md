# _USBSCAN_TIMEOUT structure

## Description

The USBSCAN_TIMEOUT structure stores time-out values for USB bulk IN and bulk OUT operations, and interrupts.

## Members

### `TimeoutRead`

Specifies the number of seconds to wait for a read operation to time out.

### `TimeoutWrite`

Specifies the number of seconds to wait for a write operation to time out.

### `TimeoutEvent`

Specifies the number of seconds to wait for an interrupt to occur.

## Remarks

A value of zero means to wait forever for the read or write operation or interrupt.

The USBSCAN_TIMEOUT structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_SET_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_set_timeout).

## See also

[IOCTL_SET_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_set_timeout)