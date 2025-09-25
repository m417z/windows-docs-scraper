# _WDF_USB_PIPE_TYPE enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_PIPE_TYPE** enumeration identifies the types of USB pipes.

## Constants

### `WdfUsbPipeTypeInvalid:0`

Reserved for internal use.

### `WdfUsbPipeTypeControl`

The pipe is a control pipe.

### `WdfUsbPipeTypeIsochronous`

The pipe is an isochronous pipe.

### `WdfUsbPipeTypeBulk`

The pipe is a bulk pipe.

### `WdfUsbPipeTypeInterrupt`

The pipe is an interrupt pipe.

## Remarks

The **WDF_USB_PIPE_TYPE** enumeration is used in the [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure.

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)