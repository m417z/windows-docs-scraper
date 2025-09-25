# WINUSB_SETUP_PACKET structure

## Description

The **WINUSB_SETUP_PACKET** structure describes a USB setup packet.

## Members

### `RequestType`

The request type. The values that are assigned to this member are defined in Table 9.2 of section 9.3 of the Universal Serial Bus (USB) specification (www.usb.org).

### `Request`

The device request. The values that are assigned to this member are defined in Table 9.3 of section 9.4 of the Universal Serial Bus (USB) specification.

### `Value`

The meaning of this member varies according to the request. For an explanation of this member, see the Universal Serial Bus (USB) specification.

### `Index`

The meaning of this member varies according to the request. For an explanation of this member, see the Universal Serial Bus (USB) specification.

### `Length`

The number of bytes to transfer.

## Remarks

Callers of the [WinUsb_ControlTransfer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_controltransfer) routine must pass in a **WINUSB_SETUP_PACKET** structure.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUsb_ControlTransfer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_controltransfer)