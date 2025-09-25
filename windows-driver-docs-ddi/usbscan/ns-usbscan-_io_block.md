# _IO_BLOCK structure

## Description

The IO_BLOCK structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_READ_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_read_registers) or [IOCTL_WRITE_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_write_registers). Values contained in structure members are used to create a USB Device Request (described in the *Universal Serial Bus Specification*).

## Members

### `uOffset`

Used as the **Value** field of a USB Device Request.

### `uLength`

Length of the buffer to transfer.

### `pbyData`

Pointer to a data buffer with a length of **uLength**.

### `uIndex`

Used as the **Index** field of a USB Device Request.