# _URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS structure

## Description

The **_URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS** structure is used by USB client drivers to retrieve delays associated with isochronous transfer programming in the host controller and transfer completion so that the client driver can ensure that the device gets the isochronous packets in time.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS, and **Hdr.Length** must be set to `sizeof(_URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS)`.

### `PipeHandle`

Specifies an opaque handle to pipe associated with the endpoint. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `MaximumSendPathDelayInMilliSeconds`

Returns the maximum delay in milliseconds from the time the client driver's isochronous transfer is received by the USB driver stack to the time the transfer is programmed in the host controller. The host controller could either be a local host (as in case of wired USB) or it could be a remote controller as in case of Media-Agnostic USB (MA-USB). In case of MA-USB, it includes the maximum delay associated with the network medium.

### `MaximumCompletionPathDelayInMilliSeconds`

Returns the maximum delay in milliseconds from the time an isochronous transfer is completed by the (local or remote) host controller to the time the corresponding client driver's request is completed by the USB driver stack. For MA-USB, it includes the maximum delay associated with the network medium.