# _URB_GET_CURRENT_FRAME_NUMBER structure

## Description

The **_URB_GET_CURRENT_FRAME_NUMBER** structure is used by USB client drivers to retrieve the current frame number.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_GET_CURRENT_FRAME_NUMBER, and **Hdr.Length** must be `sizeof(_URB_GET_CURRENT_FRAME_NUMBER)`.

### `FrameNumber`

Contains the current 32-bit frame number, on the USB bus, on return from the host controller driver.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)