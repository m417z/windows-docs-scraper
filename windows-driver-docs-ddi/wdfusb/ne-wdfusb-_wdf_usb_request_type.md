# _WDF_USB_REQUEST_TYPE enumeration (wdfusb.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_REQUEST_TYPE** enumeration identifies the types of USB requests that a framework-based driver can send to a USB I/O target.

## Constants

### `WdfUsbRequestTypeInvalid:0`

For internal use only.

### `WdfUsbRequestTypeNoFormat`

This value is not used.

### `WdfUsbRequestTypeDeviceString`

A request to [obtain a device's Unicode strings](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-devices).

### `WdfUsbRequestTypeDeviceControlTransfer`

A request to [send a control transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-devices).

### `WdfUsbRequestTypeDeviceUrb`

A request to [send a URB to a device](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-devices).

### `WdfUsbRequestTypePipeWrite`

A request to [write to a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

### `WdfUsbRequestTypePipeRead`

A request to [read from a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

### `WdfUsbRequestTypePipeAbort`

A request to [stop a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

### `WdfUsbRequestTypePipeReset`

A request to [reset a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

### `WdfUsbRequestTypePipeUrb`

A request to [send a URB to a pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

## Remarks

The **WDF_USB_REQUEST_TYPE** enumeration is used in the [WDF_USB_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_request_completion_params) structure.

## See also

[WDF_USB_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_request_completion_params)