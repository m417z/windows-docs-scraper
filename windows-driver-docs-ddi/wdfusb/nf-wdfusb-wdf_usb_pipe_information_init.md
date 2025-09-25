# WDF_USB_PIPE_INFORMATION_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_PIPE_INFORMATION_INIT** function initializes a [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure.

## Parameters

### `Info` [out]

A pointer to a [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure.

## Remarks

The **WDF_USB_PIPE_INFORMATION_INIT** function zeros the WDF_USB_PIPE_INFORMATION structure and sets the structure's **Size** member.

#### Examples

For a code example that uses **WDF_USB_PIPE_INFORMATION_INIT**, see [WdfUsbInterfaceGetEndpointInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetendpointinformation).

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)