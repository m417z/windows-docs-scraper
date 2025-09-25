# WINUSB_PIPE_INFORMATION structure

## Description

The **WINUSB_PIPE_INFORMATION** structure contains pipe information that the [WinUsb_QueryPipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_querypipe) routine retrieves.

## Members

### `PipeType`

A [USBD_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ne-usb-_usbd_pipe_type)-type enumeration value that specifies the pipe type.

### `PipeId`

The pipe identifier (ID).

### `MaximumPacketSize`

The maximum size, in bytes, of the packets that are transmitted on the pipe.

### `Interval`

The pipe interval.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[USBD_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usb/ne-usb-_usbd_pipe_type)

[WinUsb_QueryPipe](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_querypipe)