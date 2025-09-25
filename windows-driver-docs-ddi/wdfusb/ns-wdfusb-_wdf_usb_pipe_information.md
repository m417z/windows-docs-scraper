# _WDF_USB_PIPE_INFORMATION structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_PIPE_INFORMATION** structure contains information about a USB pipe and its endpoint.

## Members

### `Size`

The size, in bytes, of this structure.

### `MaximumPacketSize`

The maximum packet size, in bytes, that the pipe's endpoint is capable of sending or receiving.

For high-speed isochronous endpoints, the received **MaximumPacketSize** value includes the number of bytes that can be transferred in additional transactions, if the endpoint supports them.

### `EndpointAddress`

The address of the endpoint on the USB device. For more information about endpoint addresses, see the USB specification.

### `Interval`

The endpoint's polling interval, if the **PipeType** member is set to **WdfUsbPipeTypeInterrupt**. For more information about polling intervals, see the USB specification.

### `SettingIndex`

An index value that identifies the alternate setting, within an interface, that the pipe belongs to. For more information about alternate settings, see the USB specification.

### `PipeType`

A [WDF_USB_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_pipe_type)-typed value that specifies the type of pipe.

### `MaximumTransferSize`

This member is not used.

## Remarks

The **WDF_USB_PIPE_INFORMATION** structure is filled in by the [WdfUsbTargetPipeGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipegetinformation), [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe), and [WdfUsbInterfaceGetEndpointInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetendpointinformation) methods.

To initialize a **WDF_USB_PIPE_INFORMATION** structure, your driver should call [WDF_USB_PIPE_INFORMATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_information_init).

For more information about the **MaximumPacketSize** member of this structure, see the Remarks section of [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information).

For information on how to transfer data to and from supported isochronous endpoints in a USB device, see [How to Transfer Data to USB Isochronous Endpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information)

[WDF_USB_PIPE_INFORMATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_information_init)

[WDF_USB_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_pipe_type)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbInterfaceGetEndpointInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetendpointinformation)

[WdfUsbTargetPipeGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipegetinformation)