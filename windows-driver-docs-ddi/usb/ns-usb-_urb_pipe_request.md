# _URB_PIPE_REQUEST structure

## Description

The **_URB_PIPE_REQUEST** structure is used by USB client drivers to clear a stall condition on an endpoint.

## Members

### `Hdr`

Pointer to the [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be one of the following:

* URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL
* URB_FUNCTION_SYNC_RESET_PIPE
* URB_FUNCTION_SYNC_CLEAR_STALL
* URB_FUNCTION_ABORT_PIPE
* URB_FUNCTION_CLOSE_STATIC_STREAMS

The **Hdr.Length** member must be `sizeof(_URB_PIPE_REQUEST)`.

### `PipeHandle`

Specifies an opaque handle to the bulk or interrupt pipe. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `Reserved`

Reserved. Do not use.

## Remarks

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)