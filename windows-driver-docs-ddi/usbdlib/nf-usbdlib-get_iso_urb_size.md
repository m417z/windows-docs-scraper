# GET_ISO_URB_SIZE macro

## Description

The **GET_ISO_URB_SIZE** macro returns the number of bytes required to hold an isochronous transfer request.

## Syntax

```cpp
#define  GET_ISO_URB_SIZE(n) (sizeof(struct _URB_ISOCH_TRANSFER)+\
        sizeof(USBD_ISO_PACKET_DESCRIPTOR)*n)
```

## Parameters

### `n`

Specifies the number of isochronous transfer packets that will be part of the transfer request.

## Remarks

Gets the number of bytes required to hold an isochronous request with the given number of packets (*n*).

## See also

- [Routines for USB Client Drivers](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)
- [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)
- [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor)
- [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer)