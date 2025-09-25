# _IO_BLOCK_EX structure

## Description

The IO_BLOCK_EX structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_SEND_USB_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_send_usb_request). Values contained in structure members are used to create a USB Device Request (described in the *Universal Serial Bus Specification*).

## Members

### `uOffset`

Used as the **Value** field of a USB Device Request.

### `uLength`

Length of the buffer to transfer.

### `pbyData`

Pointer to a data buffer with a length of **uLength**.

### `uIndex`

Used as the **Index** field of a USB Device Request.

### `bRequest`

Used as the **bRequest** field of a USB Device Request.

### `bmRequestType`

Used as the **bmRequestType** field of a USB Device Request.

### `fTransferDirectionIn`

**TRUE** for transfers from device to host; **FALSE** for transfers from host to device.